/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 04:29:07 by user42            #+#    #+#             */
/*   Updated: 2022/02/17 04:29:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int	ft_getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t	ret;

	errno = 0;
	ret = getline(lineptr, n, stream);
	if (errno)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	return (ret);
}
