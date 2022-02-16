#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int	ft_getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t	ret;

	errno = 0;
	ret = getline(lineptr, n, stream);
	if (errno)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	return (ret);
}
