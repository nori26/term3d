/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:27:09 by user42            #+#    #+#             */
/*   Updated: 2022/02/17 11:14:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "draw.h"
#include "vector.h"
#include "term3d.h"

#define PHI			0.02

static double	rotation_angle_storage(double set_angle, bool is_set)
{
	static double	angle = PHI;

	if (is_set)
		angle = set_angle;
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
	static double	prev = PHI;
	double			angle;

	angle = get_rotation_angle();
	if (option == 'w' || option == 's')
		angle = get_angle_w_s(angle, option);
	else if ((option == 'a' && angle > 0) || (option == 'd' && angle < 0))
		angle *= -1;
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
