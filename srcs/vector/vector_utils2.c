/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:15:27 by user42            #+#    #+#             */
/*   Updated: 2022/02/17 09:15:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

double	dot(t_vect v1, t_vect v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vect	cross(t_vect v1, t_vect v2)
{
	return (vect_init(
			v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x));
}

t_vect	vect_unit(t_vect v)
{
	double	len;

	len = vect_len(v);
	return (vect_init(v.x / len, v.y / len, v.z / len));
}

double	vect_len(t_vect v)
{
	return (sqrt(dot(v, v)));
}

void	rotate_matrix_z(double *x, double *y, double angle)
{
	double	x_tmp;
	double	y_tmp;

	x_tmp = *x;
	y_tmp = *y;
	*x = x_tmp * cos(angle) - y_tmp * sin(angle);
	*y = x_tmp * sin(angle) + y_tmp * cos(angle);
}
