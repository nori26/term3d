#ifndef PARSE_H
# define PARSE_H
# include "term3d.h"
# include "ft_list.h"
typedef double			(*t_cmp)(double, double);

t_points	parse_lines_to_points(t_clist *lines);
t_vect		get_offest_from_origin(t_points *points);
void		get_max_or_min(t_points *points, t_vect *dest, t_cmp cmp);
void		scale_object_to_adjust_screen(t_points *points);
void		shift_points_to_center(t_points *points, t_vect *offset);
void		shift_to_center(t_points *points);

#endif
