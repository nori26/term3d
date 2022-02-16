#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <math.h>
#include "vector.h"
#include "term3d.h"
#include "input.h"

void	print_screen(char screen[][SCREEN_WIDTH])
{
	size_t	x;
	size_t	y;

	printf("\033[2j");
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			putc(screen[y][x], stdout);
			x++;
		}
		putc('\n', stdout);
		y++;
	}
}

void	init_screen(char screen[][SCREEN_WIDTH])
{
	size_t	i;

	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		memset(screen[i], ' ', SCREEN_WIDTH);
		i++;
	}
}

void	convert_vect_to_screen_coordinate(t_vect *vect, ssize_t *y, ssize_t *z)
{
	t_vect	unit;
	t_vect	coordinate;

	unit = vect_unit(*vect);
	coordinate = vect_mult(unit, CAM_TO_SCREEN_DIST);
	*y = coordinate.y;
	*z = coordinate.z;
}

bool	is_in_screen(ssize_t y, ssize_t z)
{
	return (-SCREEN_WIDTH / 2 < y && y < SCREEN_WIDTH / 2  && \
			-SCREEN_HEIGHT / 2 < z && z < SCREEN_HEIGHT / 2);
}

void	fill_screen(char screen[][SCREEN_WIDTH], ssize_t y, ssize_t z)
{
	const ssize_t	offset_origin_h = SCREEN_HEIGHT / 2;
	const ssize_t	offset_origin_w = SCREEN_WIDTH / 2;
	const ssize_t	screen_y = y + offset_origin_w;
	const ssize_t	screen_z = z + offset_origin_h;

	screen[screen_z][screen_y] = '.';
}

void	fill_screen_with_points(char screen[][SCREEN_WIDTH], t_points *points)
{
	size_t	i;
	ssize_t	y;
	ssize_t	z;
	t_vect	*vect;

	i = 0;
	while (i < points->size)
	{
		vect = &points->points[i];
		convert_vect_to_screen_coordinate(vect, &y, &z);
		if (is_in_screen(y, z))
			fill_screen(screen, y, z);
		i++;
	}
}

void	validate_terminal_size()
{
	struct winsize ws;

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

void rotate_z(t_points *points)
{
	size_t i;
	t_vect *vect;

	i = 0;
	while (i < points->size)
	{
		vect = &points->points[i];
		vect->x = vect->x * cos(PHI) - vect->y * sin(PHI);
		vect->y = vect->x * sin(PHI) + vect->y * cos(PHI);
		i++;
	}
}

void	output(t_points *points)
{
	char	screen[SCREEN_HEIGHT][SCREEN_WIDTH];

	while (1)
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

	if (argc != 2)
	{
		fprintf(stderr, "invalid argument");
		exit(EXIT_FAILURE);
	}
	validate_terminal_size();
	points = input(argv[1]);
	output(&points);
	free(points.points);
}
