/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt_uitls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 04:29:06 by user42            #+#    #+#             */
/*   Updated: 2022/02/17 04:29:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_in_table(char c, bool *table)
{
	return (c && table[(unsigned char)c]);
}

bool	is_option_chars(char *str, bool *table)
{
	if (!*str)
		return (false);
	while (is_in_table(*str, table))
		str++;
	return (*str == '\0');
}

bool	ft_is_option(char *str, bool *table)
{
	if (!str)
		return (false);
	return (str[0] == '-' && is_option_chars(&str[1], table));
}
