#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"
#include "ft_string.h"
#include "input.h"
#include "utils.h"
#include "wrapper.h"

static void	remove_empty_line(t_clist *lines)
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

static t_clist	*input_raw_lines(FILE *infile)
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

static t_clist	*input_lines(FILE *infile)
{
	t_clist	*lines;

	lines = input_raw_lines(infile);
	remove_empty_line(lines);
	return (lines);
}

t_clist	*create_line_lst_from_file(char *filename)
{
	FILE		*infile;
	t_clist		*lines;

	validate_filename(filename);
	infile = ft_fopen(filename, "r");
	lines = input_lines(infile);
	validate_lines(lines);
	fclose(infile);
	return (lines);
}
