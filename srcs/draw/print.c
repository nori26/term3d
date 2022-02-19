/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:27:09 by user42            #+#    #+#             */
/*   Updated: 2022/02/19 16:20:35 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "draw.h"

#define TERM_CLEAR 			"\033c"
#define SCREEN_CHAR_SET		" :;=co+xanm."

static char	get_screen_char(size_t density)
{
	const char		*set = SCREEN_CHAR_SET;
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
	char	c;
	size_t	x;
	size_t	y;

	printf(TERM_CLEAR);
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			c = get_screen_char(screen[y][x]);
			putchar(c);
			x++;
		}
		putchar('\n');
		y++;
	}
}
