/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:15:09 by user42            #+#    #+#             */
/*   Updated: 2022/02/17 11:17:54 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADJUST_H
# define ADJUST_H
typedef struct s_points	t_points;
typedef struct s_vect	t_vect;
typedef double			(*t_cmp)(double, double);

void	adjust_object_to_screen(t_points *points);
void	get_max_or_min(t_points *points, t_vect *dest, t_cmp cmp);
void	scale_object_to_adjust_screen(t_points *points);
void	shift_to_center(t_points *points);

#endif
