#include <stddef.h>
#include "term3d.h"
#include "vector.h"

typedef double			(*t_cmp)(double, double);

void	get_max_or_min(t_points *points, t_vect *dest, t_cmp cmp)
{
	size_t	i;
	t_vect	*vect;

	*dest = points->vects[0];
	i = 0;
	while (i < points->size)
	{
		vect = &points->vects[i];
		dest->x = cmp(dest->x, vect->x);
		dest->y = cmp(dest->y, vect->y);
		dest->z = cmp(dest->z, vect->z);
		i++;
	}
}
