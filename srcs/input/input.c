#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include "ft_list.h"
#include "vector.h"
#include "term3d.h"

bool	validate_infile(FILE *infile)
{
	char	*line;
	size_t	n;

	n = 0;
	line = NULL;
	while (true)
	{
		errno = 0;
		if (ft_getline(&line, &n, infile) == -1)
			break ;
		is_valid_num_of_fields(infile);
		free(line);
		line = NULL;
	}
	return (errno == 0);
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
	while (getline(&line, &n, infile) != -1)
	{
		if (!ft_clstnew_add_back(lines, line))
			exit(EXIT_FAILURE);
		line = NULL;
	}
}

t_vect	*input(char *filename)
{
	FILE	*infile;
	t_clist	*lines;

	infile = fopen(filename, "r");
	lines = input_lines(infile);
	validate_lines(lines);
}
