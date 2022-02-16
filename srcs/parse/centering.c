#include <stddef.h>
#include "term3d.h"
#include "vector.h"

static t_vect	get_offest_from_origin(t_points *points)
{
	t_vect	offset;
	t_vect	*vect;
	size_t	i;

	offset = (t_vect){};
	i = 0;
	while (i < points->size)
	{
		vect = &points->vects[i];
		offset = vect_add(offset, *vect);
		i++;
	}
	offset = vect_mult(offset, 1.0 / points->size);
	return (offset);
}

static void	shift_points_to_center(t_points *points, const t_vect *offset)
{
	size_t	i;
	t_vect	*vect;

	i = 0;
	while (i < points->size)
	{
		vect = &points->vects[i];
		*vect = vect_sub(*vect, *offset);
		i++;
	}
}

void	shift_to_center(t_points *points)
{
	t_vect	offset;

	offset = get_offest_from_origin(points);
	shift_points_to_center(points, &offset);
}
