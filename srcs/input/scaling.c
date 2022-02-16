#include <stdbool.h>
#include <math.h>
#include "input.h"
#include "term3d.h"
#include "vector.h"

double ft_max_dbl(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

double ft_min_dbl(double a, double b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

void	get_max_or_min(t_points *points, t_vect *dest, t_cmp cmp)
{
	size_t	i;
	t_vect	*vect;

	*dest = points->points[0];
	i = 0;
	while (i < points->size)
	{
		vect = &points->points[i];
		dest->x = cmp(dest->x, vect->x);
		dest->y = cmp(dest->y, vect->y);
		dest->z = cmp(dest->z, vect->z);
		i++;
	}
}

void	get_max_value(t_points *points, t_vect *max)
{
	get_max_or_min(points, max, ft_max_dbl);
}

void	get_min_value(t_points *points, t_vect *min)
{
	get_max_or_min(points, min, ft_min_dbl);
}

double	get_max_range(t_vect *max, t_vect *min)
{
	t_vect	range;
	double	max_range;

	range = vect_sub(*max, *min);
	range.x = fabs(range.x);
	range.y = fabs(range.y);
	range.z = fabs(range.z);
	max_range = ft_max_dbl(range.x, range.y);
	max_range = ft_max_dbl(max_range, range.z);
	return (max_range);
}

void	scale_points(t_points *points, double range)
{
	const double	height_scale = OBJ_HEIGHT / range;
	const double	width_scale = OBJ_WIDTH / range;
	size_t			i;
	t_vect			*vect;

	printf("scale %f %f\n",height_scale, width_scale);
	i = 0;
	while (i < points->size)
	{
		vect = &points->points[i];
		vect->x *= width_scale;
		vect->y *= width_scale;
		vect->z *= height_scale;
		vect->x -= CAM_TO_SCREEN_DIST;
		i++;
	}
}

void	scaling(t_points *points)
{
	double	range;
	t_vect	max;
	t_vect	min;

	get_max_value(points, &max);
	get_min_value(points, &min);
	range = get_max_range(&max, &min);
	scale_points(points, range);
}
