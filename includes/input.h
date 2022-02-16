#ifndef INPUT_H
# define INPUT_H
# include <stdio.h>
# include <stdbool.h>
# include "ft_list.h"
# include "term3d.h"
# include "vector.h"

bool	is_valid_file_extension(char *filename);
t_clist	*input(char *filename);
t_clist	*input_lines(FILE *infile);
t_clist	*input_raw_lines(FILE *infile);
void	remove_empty_line(t_clist *lines);
void	validate_coordinates(char *line, size_t line_no);
void	validate_filename(char *filename);
void	validate_lines(t_clist *lines);
void	validate_num_of_fields(char *line, size_t line_no);

#endif
