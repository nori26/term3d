#ifndef INPUT_H
# define INPUT_H
# include <stdio.h>
# include <stdbool.h>
typedef struct s_vect t_vect;

bool	validate_infile(FILE *infile);
t_vect	*input(char *filename);

#endif
