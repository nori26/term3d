#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "draw.h"
#include "vector.h"
#include "term3d.h"

#define TERM_CLEAR "\033c"
#define PHI			0.02

void	print_screen(t_screen screen)
{
	char	c;
	size_t	x;
	size_t	y;

	printf(TERM_CLEAR);
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

void	init_screen(t_screen screen)
{
	size_t	i;

	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		memset(screen[i], 0, SCREEN_WIDTH * sizeof(size_t));
		i++;
	}
}

void	rotate_z(t_points *points)
{
	size_t	i;
	double	x;
	double	y;
	t_vect	*vect;

	i = 0;
	while (i < points->size)
	{
		vect = &points->vects[i];
		x = vect->x;
		y = vect->y;
		vect->x = x * cos(PHI) - y * sin(PHI);
		vect->y = x * sin(PHI) + y * cos(PHI);
		i++;
	}
}

_Noreturn void	draw_object(t_points *points)
{
	t_screen	screen;

	while (true)
	{
		init_screen(screen);
		rotate_z(points);
		fill_screen_with_points(screen, points);
		print_screen(screen);
		usleep(10000);
	}
}
