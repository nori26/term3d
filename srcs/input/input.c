#include <stdlib.h>
#include "ft_list.h"
#include "term3d.h"
#include "input.h"

t_points	input(char *filename)
{
	t_clist		*lines;
	t_points	points;

	lines = create_line_lst_from_file(filename);
	points = parse_lines_to_points(lines);
	ft_clst_clear(&lines, free);
	return (points);
}
