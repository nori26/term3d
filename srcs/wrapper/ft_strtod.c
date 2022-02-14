#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

double	ft_strtod(char *nptr)
{
	char	*endptr;
	double	d;

	errno = 0;
	d = strtod(nptr, &endptr);
	if (*endptr || errno)
	{
		fprintf(stderr, "parse error: %s is invalid number\n", nptr);
		exit(EXIT_FAILURE);
	}
	return (d);
}
