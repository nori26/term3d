/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:11:19 by user42            #+#    #+#             */
/*   Updated: 2022/02/18 13:54:58 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "phi.h"

double	get_angle_w_s(double angle, char option)
{
	double			abs;

	abs = fabs(angle);
	if (option == 's' && abs > 0)
		abs -= PHI;
	else if (option == 'w' && abs < M_PI * 2)
		abs += PHI;
	if (angle > 0)
		angle = abs;
	else
		angle = abs * -1;
	return (angle);
}
