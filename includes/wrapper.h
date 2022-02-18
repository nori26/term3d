/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:15:09 by user42            #+#    #+#             */
/*   Updated: 2022/02/17 11:18:20 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WRAPPER_H
# define WRAPPER_H
# include <stdio.h>
enum
{
	SYS_OK = 0,
	SYS_ERR = -1,
};

FILE	*ft_fopen(const char *filename, const char *modes);
double	ft_strtod(char *nptr);
int		ft_getline(char **lineptr, size_t *n, FILE *stream);

#endif
