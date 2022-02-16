#ifndef INPUT_H
# define INPUT_H
# include <stdio.h>
# include <stdbool.h>
# include "term3d.h"
typedef struct s_vect	t_vect;
typedef struct s_clist	t_clist;
typedef double			(*t_cmp)(double, double);

bool		is_valid_file_extension(char *filename);
double		ft_max_dbl(double a, double b);
double		ft_min_dbl(double a, double b);
double		get_max_range(t_vect *max, t_vect *min);
double		get_next_coordinate(char **remained);
t_clist		*input_lines(FILE *infile);
t_clist		*input_raw_lines(FILE *infile);
t_points	input(char *filename);
t_points	parse_lines_to_vector(t_clist *lines);
t_vect		get_offest_from_origin(t_points *points);
void		*or_exit(void *allocated);
void		centering(t_points *points);
void		get_max_or_min(t_points *points, t_vect *dest, t_cmp cmp);
void		get_max_value(t_points *points, t_vect *max);
void		get_min_value(t_points *points, t_vect *min);
void		move_points_to_center(t_points *points, t_vect *offset);
void		parse_coordinate(char *line, t_vect *vect);
void		print_points(t_points points);
void		remove_empty_line(t_clist *lines);
void		scale_points(t_points *points, double range);
void		scaling(t_points *points);
void		validate_coordinates(char *line, size_t line_no);
void		validate_filename(char *filename);
void		validate_lines(t_clist *lines);
void		validate_num_of_fields(char *line, size_t line_no);

#endif
