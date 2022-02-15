#ifndef INPUT_H
# define INPUT_H
# include <stdio.h>
# include <stdbool.h>
typedef struct s_vect t_vect;
typedef struct s_clist t_clist;

bool		is_valid_file_extension(char *filename);
double		get_next_coordinate(char **remained);
t_clist		*input_lines(FILE *infile);
t_clist		*input_raw_lines(FILE *infile);
t_points	input(char *filename);
t_points	parse_lines_to_vector(t_clist *lines);
void		*or_exit(void *allocated);
void		parse_coordinate(char *line, t_vect *vect);
void		remove_empty_line(t_clist *lines);
void		validate_coordinates(char *line, size_t line_no);
void		validate_filename(char *filename);
void		validate_lines(t_clist *lines);
void		validate_num_of_fields(char *line, size_t line_no);

#endif
