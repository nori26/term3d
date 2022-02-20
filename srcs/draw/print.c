/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:27:09 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 16:27:54 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "draw.h"

#define TERM_CLEAR 			"\033[H"
#define CLEAR_SIZE			4
#define NEWLINE				1
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

static void set_image(t_screen screen, char *image)
{
	size_t	x;
	size_t	y;

	memcpy(image, TERM_CLEAR, CLEAR_SIZE);
	image += CLEAR_SIZE;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			*image++ = get_screen_char(screen[y][x]);
			x++;
		}
		*image++ = '\n';
		y++;
	}
}

static void	put_image(char *image)
{
	const size_t	len = CLEAR_SIZE + SCREEN_HEIGHT * (SCREEN_WIDTH + NEWLINE);

	write(STDOUT_FILENO, image, len);
}

void	print_screen(t_screen screen)
{
	char 	image[CLEAR_SIZE + SCREEN_HEIGHT * (SCREEN_WIDTH + NEWLINE)];

	set_image(screen, image);
	put_image(image);
}
