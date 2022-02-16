#include <stdlib.h>
#include <stdio.h>
#include "term3d.h"
#include "vector.h"

void	print_points(t_points points)
{
	size_t	i;
	t_vect	*vect;

	i = 0;
	while (i < points.size)
	{
		vect = &points.points[i];
		vect_print(vect);
		i++;
	}
	exit(0);
}

void	*or_exit(void *allocated)
{
	if (!allocated)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (allocated);
}
