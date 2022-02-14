#include <stddef.h>
#include "ft_string.h"

char	*ft_strtail(char *src, size_t tail_len)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	while (len - i > tail_len)
		i++;
	return (src + i);
}
