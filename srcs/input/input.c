#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include "input.h"
#include "ft_list.h"
#include "ft_string.h"
#include "ft_io.h"
#include "term3d.h"
#include "vector.h"
#include "wrapper.h"

#define NUM_OF_DIMENSIONS	3
#define FILE_EXTENSION		".3d"

void	*or_exit(void *allocated)
{
	if (!allocated)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (allocated);
}

void	validate_num_of_fields(char *line, size_t line_no)
{
	size_t	fields;

	fields = 1;
	while (*line)
		if (*line++ == ',')
			fields++;
	if (fields != NUM_OF_DIMENSIONS)
	{
		fprintf(stderr, "line %zu: invalid fields\n", line_no);
		exit(EXIT_FAILURE);
	}
}

void	validate_coordinates(char *line, size_t line_no)
{
	char	*num;
	char	*linecpy;
	char	*remained;

	linecpy = or_exit(ft_strdup(line));
	remained = linecpy;
	while (get_next_token(&remained, ",", &num))
	{
		if (!strlen(num))
		{
			fprintf(stderr, "line %zu: invalid coordinate\n", line_no);
			exit(EXIT_FAILURE);
		}
		ft_strtod(num);
	}
	free(linecpy);
}

void	validate_lines(t_clist *lines)
{
	char	*line;
	size_t	line_no;

	line_no = 0;
	lines = ft_clstfirst(lines);
	while (!ft_clst_isend(lines))
	{
		line_no++;
		line = lines->data;
		validate_num_of_fields(line, line_no);
		validate_coordinates(line, line_no);
		lines = lines->next;
	}
}

void	remove_empty_line(t_clist *lines)
{
	char	*line;

	lines = ft_clstfirst(lines);
	while (!ft_clst_isend(lines))
	{
		line = lines->data;
		if (!*line)
			ft_clst_popdel(lines, free);
		lines = lines->next;
	}
}

t_clist	*input_raw_lines(FILE *infile)
{
	char	*line;
	char	*trimed_endl;
	size_t	n;
	t_clist	*lines;

	lines = or_exit(ft_clstnew(NULL));
	n = 0;
	line = NULL;
	while (ft_getline(&line, &n, infile) != -1)
	{
		trimed_endl = or_exit(ft_strtrim(line, "\n"));
		or_exit(ft_clstnew_add_back(lines, trimed_endl));
		free(line);
		line = NULL;
	}
	free(line);
	return (lines);
}

t_clist	*input_lines(FILE *infile)
{
	t_clist	*lines;

	lines = input_raw_lines(infile);
	remove_empty_line(lines);
	return (lines);
}

double	get_next_coordinate(char **remained)
{
	char	*num;

	get_next_token(remained, ",", &num);
	return (ft_strtod(num));
}

void	parse_coordinate(char *line, t_vect *vect)
{
	char	*linecpy;
	char	*remained;

	linecpy = or_exit(ft_strdup(line));
	remained = linecpy;
	vect->x = get_next_coordinate(&remained);
	vect->y = get_next_coordinate(&remained);
	vect->z = get_next_coordinate(&remained);
	free(linecpy);
}

t_points	parse_lines_to_vector(t_clist *lines)
{
	size_t		i;
	t_vect		*point;
	t_points	points;
	char		*line;

	i = 0;
	points.size = ft_clst_size(lines);
	if (!points.size)
		exit(EXIT_SUCCESS);
	points.points = or_exit(malloc(sizeof(t_vect) * points.size));
	lines = ft_clstfirst(lines);
	while (!ft_clst_isend(lines))
	{
		line = lines->data;
		point = &points.points[i];
		parse_coordinate(line, point);
		lines = lines->next;
		i++;
	}
	return (points);
}

bool	is_valid_file_extension(char *filename)
{
	const size_t	extension_size = strlen(FILE_EXTENSION);
	const char		*extension = ft_strtail(filename, extension_size);
	const char		*tail = ft_strtail(filename, extension_size + 1);
	const bool		is_hidden_file = ft_streq(filename, FILE_EXTENSION) || \
									ft_streq(tail, "/"FILE_EXTENSION);

	return (!is_hidden_file && ft_streq(extension, FILE_EXTENSION));
}

void	validate_filename(char *filename)
{
	if (is_valid_file_extension(filename))
		return ;
	else
	{
		fprintf(stderr, "%s is invalid file\n", filename);
		exit(EXIT_FAILURE);
	}
}

void	print_points(t_points points)
{
	size_t	i;
	t_vect	*vect;

	i = 0;
	while (i < points.size)
	{
		vect = &points.points[i];
		vect_print(vect);
		i++;
	}
	exit(0);
}

t_points	input(char *filename)
{
	t_points	points;
	FILE		*infile;
	t_clist		*lines;

	validate_filename(filename);
	infile = ft_fopen(filename, "r");
	lines = input_lines(infile);
	validate_lines(lines);
	points = parse_lines_to_vector(lines);
	centering(&points);
	scaling(&points);
	ft_clst_clear(&lines, free);
	fclose(infile);
	return (points);
}
