/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:27:09 by user42            #+#    #+#             */
/*   Updated: 2022/02/19 16:15:53 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "keyhook.h"

static void	set_rotate_speed(int key_input, t_option *option)
{
	if (key_input == 'w')
		option->rotate_speed = FAST;
	else if (key_input == 's')
		option->rotate_speed = SLOW;
	else if (key_input == 'a')
		option->rotate_speed = LEFT;
	else if (key_input == 'd')
		option->rotate_speed = RIGHT;
	else if (key_input == ' ')
		option->rotate_speed = PAUSE;
}

static void	set_zoom_rate(int key_input, t_option *option)
{
	if (key_input == 'i')
		option->zoom_rate = ZOOM_IN;
	else if (key_input == 'o')
		option->zoom_rate = ZOOM_OUT;
}

static void	set_reset_flag(int key_input, t_option *option)
{
	if (key_input == 'r')
		option->reset = true;
}

void	parse_option(int key_input, t_option *option)
{
	*option = (t_option){};
	set_reset_flag(key_input, option);
	set_rotate_speed(key_input, option);
	set_zoom_rate(key_input, option);
}
