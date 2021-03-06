/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 04:29:07 by user42            #+#    #+#             */
/*   Updated: 2022/02/17 04:29:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"
#include "ft_string.h"
#include "utils.h"
#include "wrapper.h"

#define NUM_OF_DIMENSIONS	3

static void	validate_num_of_fields(const char *line, size_t line_no)
{
	size_t	fields;

	fields = 1;
	while (*line)
	{
		if (*line == ',')
			fields++;
		line++;
	}
	if (fields != NUM_OF_DIMENSIONS)
	{
		fprintf(stderr, "line %zu: invalid fields\n", line_no);
		exit(EXIT_FAILURE);
	}
}

static void	validate_coordinates(const char *line, size_t line_no)
{
	char	*num;
	char	*linecpy;
	char	*remained;

	linecpy = or_exit(ft_strdup(line));
	remained = linecpy;
	while (get_next_token(&remained, ",", &num))
	{
		if (!strlen(num))
		{
			fprintf(stderr, "line %zu: invalid coordinate\n", line_no);
			exit(EXIT_FAILURE);
		}
		ft_strtod(num);
	}
	free(linecpy);
}

void	validate_lines(t_clist *lines)
{
	char	*line;
	size_t	line_no;

	line_no = 0;
	lines = ft_clstfirst(lines);
	while (!ft_clst_isend(lines))
	{
		line_no++;
		line = lines->data;
		validate_num_of_fields(line, line_no);
		validate_coordinates(line, line_no);
		lines = lines->next;
	}
}
