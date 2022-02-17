/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 04:29:07 by user42            #+#    #+#             */
/*   Updated: 2022/02/17 04:29:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vect	vect_init(double x, double y, double z)
{
	t_vect	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_vect	vect_add(t_vect v1, t_vect v2)
{
	return (vect_init(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_vect	vect_sub(t_vect v1, t_vect v2)
{
	return (vect_init(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_vect	vect_mult(t_vect v, double d)
{
	return (vect_init(v.x * d, v.y * d, v.z * d));
}
