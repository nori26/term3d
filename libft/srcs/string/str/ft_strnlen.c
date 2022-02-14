#include <stddef.h>

size_t	ft_strnlen(char *s, size_t limit)
{
	size_t	i;

	i = 0;
	while (i < limit && s[i])
		i++;
	return (i);
}
