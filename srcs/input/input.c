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
		// validate_fields(line, line_no);
		lines = lines->next;
	}
}

t_clist	*input_lines(FILE *infile)
{
	char	*line;
	size_t	n;
	t_clist	*lines;

	lines = ft_clstnew(NULL);
	if(!lines)
		exit(EXIT_FAILURE);
	n = 0;
	line = NULL;
	while (ft_getline(&line, &n, infile) != -1)
	{
		if (!ft_clstnew_add_back(lines, line))
			exit(EXIT_FAILURE);
		line = NULL;
	}
	return (lines);
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
	validate_lines(lines);
	// points = parse_lines_to_vector();
	ft_clst_clear(&lines, free);
	return (NULL);
}
