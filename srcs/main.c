#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "vector.h"
#include "term3d.h"
#include "input.h"

void	print_screen(char screen[][SCREEN_SIZE])
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < SCREEN_SIZE)
	{
		x = 0;
		while (x < SCREEN_SIZE)
		{
			putc(screen[y][x], stdout);
			x++;
		}
		putc('\n', stdout);
		y++;
	}
}

void	init_screen(char screen[][SCREEN_SIZE])
{
	size_t	i;

	while (i < SCREEN_SIZE)
	{
		memset(screen[i], ' ', SCREEN_SIZE);
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
	return (-SCREEN_SIZE / 2 < y && y < SCREEN_SIZE / 2  && \
			-SCREEN_SIZE / 2 < z && z < SCREEN_SIZE / 2);
}

void	fill_screen(char screen[][SCREEN_SIZE], ssize_t y, ssize_t z)
{
	const ssize_t	offset_origin = SCREEN_SIZE / 2;
	const ssize_t	screen_y = y + offset_origin;
	const ssize_t	screen_z = z + offset_origin;

	screen[screen_z][screen_y] = '.';
}

void	fill_screen_with_points(char screen[][SCREEN_SIZE], t_points *points)
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
	if (ws.ws_col < SCREEN_SIZE)
	{
		fprintf(stderr, "terminal width too short");
		exit(EXIT_FAILURE);
	}
}

void	output(t_points *points)
{
	char	screen[SCREEN_SIZE][SCREEN_SIZE];

	init_screen(screen);
	fill_screen_with_points(screen, points);
	print_screen(screen);
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
