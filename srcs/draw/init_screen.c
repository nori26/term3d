/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:20:34 by user42            #+#    #+#             */
/*   Updated: 2022/02/17 10:21:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stddef.h>
#include "draw.h"

void	init_screen(t_screen screen)
{
	size_t	i;

	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		memset(screen[i], 0, SCREEN_WIDTH * sizeof(size_t));
		i++;
	}
}
