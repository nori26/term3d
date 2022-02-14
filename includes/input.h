#ifndef INPUT_H
# define INPUT_H
# include <stdio.h>
# include <stdbool.h>
typedef struct s_vect t_vect;
typedef struct s_clist t_clist;

t_clist	*input_lines(FILE *infile);
t_vect	*input(char *filename);
void	validate_lines(t_clist *lines);
void	validate_num_of_fields(char *line, size_t line_no);

#endif
