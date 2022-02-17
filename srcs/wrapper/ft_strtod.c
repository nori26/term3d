/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 04:29:07 by user42            #+#    #+#             */
/*   Updated: 2022/02/17 04:29:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

double	ft_strtod(char *nptr)
{
	char	*endptr;
	double	d;

	errno = 0;
	d = strtod(nptr, &endptr);
	if (*endptr || errno)
	{
		fprintf(stderr, "parse error: %s is invalid number\n", nptr);
		exit(EXIT_FAILURE);
	}
	return (d);
}
