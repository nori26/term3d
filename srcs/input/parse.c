/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 04:29:07 by user42            #+#    #+#             */
/*   Updated: 2022/02/17 04:29:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "ft_list.h"
#include "utils.h"
#include "term3d.h"
#include "vector.h"
#include "wrapper.h"

static double	get_next_coordinate(char **remained)
{
	char	*num;

	get_next_token(remained, ",", &num);
	return (ft_strtod(num));
}

static void	parse_coordinate(const char *line, t_vect *vect)
{
	char	*linecpy;
	char	*remained;

	linecpy = or_exit(ft_strdup(line));
	remained = linecpy;
	vect->x = get_next_coordinate(&remained);
	vect->y = get_next_coordinate(&remained);
	vect->z = get_next_coordinate(&remained);
	free(linecpy);
}

static void	parse_lines_to_vectors(t_clist *lines, t_points *points)
{
	size_t		i;
	t_vect		*point;
	char		*line;

	i = 0;
	lines = ft_clstfirst(lines);
	while (!ft_clst_isend(lines))
	{
		line = lines->data;
		point = &points->vects[i];
		parse_coordinate(line, point);
		lines = lines->next;
		i++;
	}
}

static void	init_points(t_points *points, t_clist *lines)
{
	points->size = ft_clst_size(lines);
	points->vects = or_exit(malloc(sizeof(t_vect) * points->size));
}

t_points	parse_lines_to_points(t_clist *lines)
{
	t_points	points;

	init_points(&points, lines);
	if (!points.size)
		exit(EXIT_SUCCESS);
	parse_lines_to_vectors(lines, &points);
	return (points);
}
