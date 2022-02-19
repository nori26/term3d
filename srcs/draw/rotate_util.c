/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:11:19 by user42            #+#    #+#             */
/*   Updated: 2022/02/19 02:53:55 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "phi.h"
#include "draw.h"

static int	get_angle_sign(double angle)
{
	if (angle > 0)
		return (1);
	else
		return (-1);
}

double	update_angle_level(double angle, char option)
{
	double	abs;
	int		sign;

	abs = fabs(angle);
	sign = get_angle_sign(angle);
	if (option == 's' && abs > 0)
		abs -= PHI;
	else if (option == 'w' && abs < M_PI * 2)
		abs += PHI;
	return (abs * sign);
}

double	toggle_rotation(double angle)
{
	static double	prev;
	double			new_angle;

	if (angle)
	{
		prev = get_rotation_angle();
		new_angle = 0;
	}
	else
		new_angle = prev;
	return (new_angle);
}
