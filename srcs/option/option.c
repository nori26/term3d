/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:27:09 by user42            #+#    #+#             */
/*   Updated: 2022/02/17 09:27:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "option.h"

void	get_rotate_speed(char key_input, t_option *option)
{
	if (ft_strchr("wasd ", key_input))
		option->rotate_speed = key_input;
}

void	get_zoom_rate(char key_input, t_option *option)
{
	if (key_input == 'i' || key_input == 'o')
		option->zoom_rate = key_input;
}

void	get_shift_coordinate(char key_input, t_option *option)
{
	if (ft_strchr("WASD", key_input))
		option->shift_coordinate = key_input;
}

void	get_reset_flag(char key_input, t_option *option)
{
	if (key_input == 'r')
		option->reset = true;
}

void	option_handler(char key_input, t_option *option)
{
	*option = (t_option){};
	if (key_input == 'q')
		exit(EXIT_SUCCESS);
	get_reset_flag(key_input, option);
	get_rotate_speed(key_input, option);
	get_zoom_rate(key_input, option);
	get_shift_coordinate(key_input, option);
}
