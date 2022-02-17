#ifndef INPUT_H
# define INPUT_H
# include <stdio.h>
# include <stdbool.h>
typedef struct s_points	t_points;
typedef struct s_clist	t_clist;
typedef struct s_vect	t_vect;

t_clist		*create_line_lst_from_file(char *filename);
t_points	input(char *filename);
t_points	parse_lines_to_points(t_clist *lines);
void		validate_filename(char *filename);
void		validate_lines(t_clist *lines);

#endif
