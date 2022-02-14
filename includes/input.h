#ifndef INPUT_H
# define INPUT_H
# include <stdio.h>
# include <stdbool.h>
typedef struct s_vect t_vect;
typedef struct s_clist t_clist;

t_clist	*input_lines(FILE *infile);
t_vect	*input(char *filename);

#endif
