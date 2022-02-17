/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 04:29:07 by user42            #+#    #+#             */
/*   Updated: 2022/02/17 04:29:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include "stdlib.h"

FILE	*ft_fopen(const char *filename, const char *modes)
{
	FILE	*file;

	errno = 0;
	file = fopen(filename, modes);
	if (errno)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	return (file);
}
