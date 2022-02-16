#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ft_string.h"

#define FILE_EXTENSION ".3d"

static bool	is_valid_file_extension(char *filename)
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
		fprintf(stderr, "%s is invalid file format\n", filename);
		exit(EXIT_FAILURE);
	}
}
