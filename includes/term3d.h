/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 04:29:06 by user42            #+#    #+#             */
/*   Updated: 2022/02/17 11:18:05 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM3D_H
# define TERM3D_H
# include <stddef.h>

typedef struct s_vect	t_vect;
typedef struct s_points
{
	size_t	size;
	t_vect	*vects;
}	t_points;

#endif
