/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:27:09 by user42            #+#    #+#             */
/*   Updated: 2022/02/17 11:18:04 by nosuzuki         ###   ########.fr       */
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

void	hook_key_input(t_option *option);
void	parse_option(char key_input, t_option *option);

#endif
