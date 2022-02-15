/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 04:11:35 by nosuzuki          #+#    #+#             */
/*   Updated: 2022/01/26 10:47:52 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

char	**ft_free_strs(char ***ret)
{
	size_t	i;

	i = 0;
	while ((*ret)[i])
	{
		free((*ret)[i]);
		(*ret)[i++] = 0;
	}
	free(*ret);
	return (*ret = NULL);
}
