#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "draw.h"
#include "vector.h"
#include "term3d.h"

#define TERM_CLEAR "\033c"
#define PHI			0.02

static char	get_screen_char(size_t density)
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

static void	print_screen(t_screen screen)
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

static void	init_screen(t_screen screen)
{
	size_t	i;

	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		memset(screen[i], 0, SCREEN_WIDTH * sizeof(size_t));
		i++;
	}
}

static void	rotate_z(t_points *points)
{
	size_t	i;
	t_vect	*vect;

	i = 0;
	while (i < points->size)
	{
		vect = &points->vects[i];
		rotate_matrix_z(&vect->x, &vect->y, PHI);
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
		usleep(100000);
	}
}