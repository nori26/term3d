/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:27:09 by user42            #+#    #+#             */
/*   Updated: 2022/02/17 10:23:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "draw.h"
#include "vector.h"
#include "term3d.h"
#include "keyhook.h"
#include "utils.h"

static void	reset_coordinate(t_points *points, t_points *base)
{
	memcpy(points->vects, base->vects, sizeof(t_vect) * base->size);
}

static t_points	create_points_copy(t_points *points)
{
	t_points	cpy;

	cpy.size = points->size;
	cpy.vects = or_exit(malloc(sizeof(t_vect) * cpy.size));
	memcpy(cpy.vects, points->vects, sizeof(t_vect) * cpy.size);
	return (cpy);
}

static void	alter_coordinate(t_points *points, t_points *base, t_option *option)
{
	if (option->reset)
	{
		reset_coordinate(points, base);
		reset_rotation_angle();
	}
	else
	{
		zoom_object(option->zoom_rate, points);
		set_rotation_angle(option->rotate_speed);
	}
	rotate_z(points);
}

static void	draw_object(t_points *points)
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
