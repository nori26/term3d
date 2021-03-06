/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 04:29:07 by user42            #+#    #+#             */
/*   Updated: 2022/02/18 13:42:49 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include "term3d.h"
#include "input.h"

t_points	read_points_from_file(char *filename)
{
	t_clist		*lines;
	t_points	points;

	lines = create_line_lst_from_file(filename);
	points = parse_lines_to_points(lines);
	ft_clst_clear(&lines, free);
	return (points);
}
