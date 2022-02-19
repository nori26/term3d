/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:27:09 by user42            #+#    #+#             */
/*   Updated: 2022/02/19 03:10:13 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include <stdbool.h>
# include <stddef.h>
# define SCREEN_HEIGHT	50
# define SCREEN_WIDTH	65
typedef struct s_points	t_points;
typedef struct s_option	t_option;
typedef size_t			t_screen[SCREEN_HEIGHT + 1][SCREEN_WIDTH + 1];

_Noreturn void	draw(t_points *points);
double			update_angle_level(double angle, char option);
double			get_rotation_angle(void);
void			fill_screen_with_points(t_screen screen, t_points *points);
void			init_screen(t_screen screen);
void			print_screen(t_screen screen);
void			reset_rotation_angle(void);
double			toggle_rotation(double angle);
void			rotate_z(t_points *points);
void			set_rotation_angle(char option);
void			zoom_object(char option, t_points *points);

#endif
