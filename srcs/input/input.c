#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include "ft_list.h"
#include "ft_string.h"
#include "ft_io.h"
#include "vector.h"
#include "wrapper.h"

#define NUM_OF_DIMENSIONS 3

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
		fprintf(stderr, "line: %zu invalid fields\n", line_no);
		exit(EXIT_FAILURE);
	}
}

void	validate_coordinates(char *line, size_t line_no)
{
	char	*num;
	char	*remained;

	remained = or_exit(ft_strdup(line));
	while (get_next_token(&remained, ",", &num))
	{
		if (!strlen(num))
			exit(EXIT_FAILURE);
		ft_strtod(num);
	}
	free(remained);
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

t_clist	*input_lines(FILE *infile)
{
	char	*line;
	size_t	n;
	t_clist	*lines;

	lines = or_exit(ft_clstnew(NULL));
	n = 0;
	line = NULL;
	while (ft_getline(&line, &n, infile) != -1)
	{
		or_exit(ft_clstnew_add_back(lines, line));
		line = NULL;
	}
	return (lines);
}

t_vect	*parrse_lines_to_vector(t_clist	*lines)
{
	size_t	size;
	char	*line;

	lines = ft_clstfirst(lines);
	while (!ft_clst_isend(lines))
	{
		line = lines->data;
		lines = lines->next;
	}
}

t_vect	*input(char *filename)
{
	t_vect	*points;
	FILE	*infile;
	t_clist	*lines;

	(void)lines;
	(void)points;
	// validate_filename();
	infile = ft_fopen(filename, "r");
	lines = input_lines(infile);
	remove_empty_line(lines);
	validate_lines(lines);
	points = parse_lines_to_vector();
	ft_clst_clear(&lines, free);
	return (NULL);
}
