#ifndef PARSE_H
# define PARSE_H
# include "term3d.h"
# include "ft_list.h"
typedef double			(*t_cmp)(double, double);

t_points	parse_lines_to_points(t_clist *lines);
void		get_max_or_min(t_points *points, t_vect *dest, t_cmp cmp);
void		scale_object_to_adjust_screen(t_points *points);
void		shift_to_center(t_points *points);

#endif
