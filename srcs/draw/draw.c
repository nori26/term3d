#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include "draw.h"
#include "vector.h"
#include "term3d.h"
#include "keyhook.h"

#include "utils.h"
#include <stdlib.h>

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

void	reset_coordinate(t_points *points, t_points *base)
{
	memcpy(points->vects, base->vects, sizeof(t_vect) * base->size);
	reset_rotation_angle();
}

void	alter_coordinate(t_points *points, t_points *base, t_option *option)
{
	if (option->reset)
		reset_coordinate(points, base);
	else
	{
		zoom_object(option.zoom_rate, points);
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

void	draw_object(t_points *points)
{
	t_screen	screen;

	init_screen(screen);
	fill_screen_with_points(screen, points);
	print_screen(screen);
}

_Noreturn void	draw(t_points *points)
{
	t_points	base;
	t_option	option;

	base = create_points_copy(points);
	while (true)
	{
		hook_key_input(&option);
		alter_coordinate(points, &base, &option);
		draw_object(points);
		usleep(10000);
	}
}
