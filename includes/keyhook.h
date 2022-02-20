/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:27:09 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 02:48:22 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYHOOK_H
# define KEYHOOK_H
# include <stdbool.h>
# include <termios.h>
typedef struct s_option
{
	bool	reset;
	char	rotate_speed;
	char	zoom_rate;
}	t_option;
typedef struct s_default
{
	struct termios	term;
	int				fcntl;
}	t_default_setting;
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

char	getchar_non_blocking(void);
void	hook_key_input(t_option *option);
void	parse_option(int key_input, t_option *option);

#endif
