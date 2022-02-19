/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:27:09 by user42            #+#    #+#             */
/*   Updated: 2022/02/19 04:04:28 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "draw.h"

#include <unistd.h>
#define TERM_CLEAR "\033c"
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

// void	print_screen(t_screen screen)
// {
// 	char	c;
// 	size_t	x;
// 	size_t	y;

// 	printf(TERM_CLEAR);
// 	y = 0;
// 	while (y < SCREEN_HEIGHT)
// 	{
// 		x = 0;
// 		while (x < SCREEN_WIDTH)
// 		{
// 			c = get_screen_char(screen[y][x]);
// 			putchar(c);
// 			x++;
// 		}
// 		putchar('\n');
// 		y++;
// 	}
// }
#define ENDLINE 1
void	print_screen(t_screen screen)
{
	size_t	i;
	char	object[SCREEN_HEIGHT * (SCREEN_WIDTH + ENDLINE)];
	size_t	x;
	size_t	y;

	write(STDERR_FILENO, TERM_CLEAR, sizeof(TERM_CLEAR) - 1);
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
	// i = 0;
	// while (i < SCREEN_HEIGHT * (SCREEN_WIDTH + ENDLINE))
	// {
	// 	putchar(object[i]);
	// 	i++;
	// }
	write(STDOUT_FILENO, object, SCREEN_HEIGHT * (SCREEN_WIDTH + ENDLINE));
}
