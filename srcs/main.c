#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <math.h>
#include "ft_list.h"
#include "parse.h"
#include "vector.h"
#include "term3d.h"
#include "input.h"

char	get_screen_char(size_t density)
{
	const char		*set = " :;=co+xanm.";
	const size_t	size = strlen(set);
	size_t			idx;

	if (density >= size)
		idx = size - 1;
	else
		idx = density;
	return (set[idx]);
}

void	print_screen(size_t screen[][SCREEN_WIDTH])
{
	char	c;
	size_t	x;
	size_t	y;

	printf("\033c");
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			c = get_screen_char(screen[y][x]);
			putchar(c);
			x++;
		}
		putchar('\n');
		y++;
	}
}

void	init_screen(size_t screen[][SCREEN_WIDTH])
{
	size_t	i;

	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		memset(screen[i], 0, SCREEN_WIDTH * sizeof(size_t));
		i++;
	}
}

bool	is_in_screen(ssize_t y, ssize_t z)
{
	return (-SCREEN_WIDTH / 2 < y && y < SCREEN_WIDTH / 2 && \
			-SCREEN_HEIGHT / 2 < z && z < SCREEN_HEIGHT / 2);
}

void	fill_screen(size_t screen[][SCREEN_WIDTH], ssize_t y, ssize_t z)
{
	const ssize_t	offset_origin_h = SCREEN_HEIGHT / 2;
	const ssize_t	offset_origin_w = SCREEN_WIDTH / 2;
	const ssize_t	screen_y = y + offset_origin_w;
	const ssize_t	screen_z = z + offset_origin_h;

	screen[screen_z][screen_y]++;
}

void	fill_screen_with_points(size_t screen[][SCREEN_WIDTH], t_points *points)
{
	size_t	i;
	t_vect	*vect;

	i = 0;
	while (i < points->size)
	{
		vect = &points->points[i];
		if (is_in_screen(vect->y, vect->z))
			fill_screen(screen, vect->y, vect->z);
		i++;
	}
}

void	validate_terminal_size(void)
{
	struct winsize	ws;

	if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1)
	{
		perror("ioctl");
		exit(EXIT_FAILURE);
	}
	if (ws.ws_col < SCREEN_WIDTH)
	{
		fprintf(stderr, "terminal width too short");
		exit(EXIT_FAILURE);
	}
}

void	rotate_z(t_points *points)
{
	size_t	i;
	t_vect	*vect;

	i = 0;
	while (i < points->size)
	{
		vect = &points->points[i];
		vect->x = vect->x * cos(PHI) - vect->y * sin(PHI);
		vect->y = vect->x * sin(PHI) + vect->y * cos(PHI);
		i++;
	}
}

_Noreturn void	draw_object(t_points *points)
{
	size_t	screen[SCREEN_HEIGHT][SCREEN_WIDTH];

	while (true)
	{
		init_screen(screen);
		rotate_z(points);
		fill_screen_with_points(screen, points);
		print_screen(screen);
		usleep(10000);
	}
}

int	main(int argc, char **argv)
{
	t_points	points;
	t_clist		*lines;

	if (argc != 2)
	{
		fprintf(stderr, "invalid argument");
		exit(EXIT_FAILURE);
	}
	validate_terminal_size();
	lines = input(argv[1]);
	points = parse_lines_to_points(lines);
	ft_clst_clear(&lines, free);
	draw_object(&points);
	free(points.points);
}
