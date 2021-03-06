/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:27:09 by user42            #+#    #+#             */
/*   Updated: 2022/02/19 16:17:30 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "keyhook.h"
#include "draw.h"
#include "vector.h"
#include "term3d.h"
#include "phi.h"

static double	rotation_angle_storage(double new_angle, bool is_set)
{
	static double	angle = PHI;

	if (is_set)
		angle = new_angle;
	return (angle);
}

void	reset_rotation_angle(void)
{
	rotation_angle_storage(PHI, true);
}

double	get_rotation_angle(void)
{
	return (rotation_angle_storage(0, false));
}

void	set_rotation_angle(char option)
{
	double			angle;

	angle = get_rotation_angle();
	if (option == FAST || option == SLOW)
		angle = update_angle_level(angle, option);
	else if ((option == LEFT && angle > 0) || (option == RIGHT && angle < 0))
		angle *= -1;
	else if (option == PAUSE)
		angle = toggle_rotation(angle);
	rotation_angle_storage(angle, true);
}

void	rotate_z(t_points *points)
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
