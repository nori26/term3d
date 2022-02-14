#include <stdio.h>
#include <errno.h>

FILE	*ft_fopen(char *filename, char *modes)
{
	FILE	*file;

	errno = 0;
	file = fopen(filename, modes);
	if (errno)
		perror("fopen");
	return (file);
}
