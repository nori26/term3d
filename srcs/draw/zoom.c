#include <string.h>
#include "draw.h"
#include "vector.h"
#include "term3d.h"
#include "utils.h"

void	zoom_by_scale(t_points *points, double scale)
{
	size_t	i;
	t_vect	*vect;

	i = 0;
	while (i < points->size)
	{
		vect = &points->vects[i];
		vect->x = vect->x * scale;
		vect->y = vect->y * scale;
		vect->z = vect->z * scale;
		i++;
	}
}

void	zoom_in(t_points *points)
{
	zoom_by_scale(points, 1.1);
}

void	zoom_out(t_points *points)
{
	zoom_by_scale(points, 0.9);
}

void	zoom_object(char option, t_points *points)
{
	if (option == 'i')
		zoom_in(points);
	else if (option == 'o')
		zoom_out(points);
}
