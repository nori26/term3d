/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:27:09 by user42            #+#    #+#             */
/*   Updated: 2022/02/19 03:22:57 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "draw.h"

#define TERM_CLEAR "\033c"
#define ENDLINE		1

static char	get_screen_char(size_t density)
{
	const char		*set = " :;=co+xanm.";
	const size_t	size = strlen(set);
	size_t			idx;

	if (density >= size)
		idx = size - 1;
	else
		idx = density;
	return (set[idx]);
}

void	print_screen(t_screen screen)
{
	size_t	i;
	char	object[SCREEN_HEIGHT * (SCREEN_WIDTH + ENDLINE)];
	size_t	x;
	size_t	y;

	printf(TERM_CLEAR);
	i = 0;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			object[i++] = get_screen_char(screen[y][x]);
			x++;
		}
		object[i++] = '\n';
		y++;
	}
	write(STDOUT_FILENO, object, SCREEN_HEIGHT * (SCREEN_WIDTH + ENDLINE));
}
