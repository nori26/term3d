/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:27:09 by user42            #+#    #+#             */
/*   Updated: 2022/02/19 16:15:25 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYHOOK_H
# define KEYHOOK_H
# include <stdbool.h>
typedef struct s_option
{
	bool	reset;
	char	rotate_speed;
	char	zoom_rate;
}	t_option;

enum
{
	FAST = 1,
	SLOW,
	LEFT,
	RIGHT,
	PAUSE,
	ZOOM_IN,
	ZOOM_OUT,
};

void	hook_key_input(t_option *option);
void	parse_option(int key_input, t_option *option);

#endif
