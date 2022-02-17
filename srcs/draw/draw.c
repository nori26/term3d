#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include "draw.h"
#include "vector.h"
#include "term3d.h"
#include "option.h"

#include "utils.h"
#include <stdlib.h>
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

double	rotation_angle_storage(double set_angle, bool is_set)
{
	static double	angle = PHI;

	if (is_set)
		angle = set_angle;
	return (angle);
}

double	get_rotation_angle()
{
	return (rotation_angle_storage(0, false));
}

void	set_rotation_angle(char option)
{
	static double	prev = PHI;
	double			angle;

	angle = get_rotation_angle();
	if (option == 's' && angle > 0)
		angle -= PHI;
	else if (option == 'w' && angle < 6.28)
		angle += PHI;
	else if (option == ' ')
	{
		if (angle)
		{
			prev = get_rotation_angle();
			angle = 0;
		}
		else
			angle = prev;
	}
	else if (option == 'a' && angle > 0) 
		angle = -angle;
	else if (option == 'd' && angle < 0)
		angle = -angle;
	rotation_angle_storage(angle, true);
}

static void	rotate_z(t_points *points)
{
	size_t	i;
	t_vect	*vect;
	double	theta;

	theta = get_rotation_angle();
	i = 0;
	while (i < points->size)
	{
		vect = &points->vects[i];
		rotate_matrix_z(&vect->x, &vect->y, theta);
		i++;
	}
}

void	reset_rotation_angle(double set_angle, bool is_set)
{
	rotation_angle_storage(set_angle, is_set);
}

void	reset_coordinate(t_points *points, const t_points *base)
{
	memcpy(points->vects, base->vects, sizeof(t_vect) * base->size);
	reset_rotation_angle(PHI, true);
}

void	alter_coordinate(t_points *points, const t_points *base)
{
	t_option		option;
	char			key_input;

	key_input = getchar();
	option_handler(key_input, &option);
	if (option.reset)
		reset_coordinate(points, base);
	else
	{
		//zoom_object(option.zoom_rate, points);
		// shift_object();
		set_rotation_angle(option.rotate_speed);
	}
	rotate_z(points);
}

t_points	create_points_copy(t_points *points)
{
	t_points	cpy;

	cpy.size = points->size;
	cpy.vects = or_exit(malloc(sizeof(t_vect) * cpy.size));
	memcpy(cpy.vects, points->vects, sizeof(t_vect) * cpy.size);
	return (cpy);
}

_Noreturn void	draw_object(t_points *points)
{
	const t_points	base = create_points_copy(points);
	t_screen		screen;

	while (true)
	{
		alter_coordinate(points, &base);
		init_screen(screen);
		fill_screen_with_points(screen, points);
		print_screen(screen);
		usleep(10000);
	}
}
