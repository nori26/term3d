#include <stdio.h>
#include <errno.h>

int	ft_getline(char **lineptr, size_t *n, FILE *stream)
{
	int	ret;

	errno = 0;
	ret = getline(lineptr, n, stream);
	if (errno)
		perror("getline");
	return (ret);
}
