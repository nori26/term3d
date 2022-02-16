#ifndef INPUT_H
# define INPUT_H
# include <stdio.h>
# include <stdbool.h>
typedef struct s_points	t_points;
typedef struct s_clist	t_clist;
typedef struct s_vect	t_vect;

t_clist	*input(char *filename);
void	validate_filename(char *filename);
void	validate_lines(t_clist *lines);

#endif
