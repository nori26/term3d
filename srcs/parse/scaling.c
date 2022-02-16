#include <math.h>
#include "ft_utils.h"
#include "parse.h"
#include "term3d.h"
#include "vector.h"

#define OBJ_HEIGHT	45
#define OBJ_WIDTH	60

static void	get_max_value(t_points *points, t_vect *max)
{
	get_max_or_min(points, max, ft_max_dbl);
}

static void	get_min_value(t_points *points, t_vect *min)
{
	get_max_or_min(points, min, ft_min_dbl);
}

static double	get_max_range(t_vect *max, t_vect *min)
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

static void	scale_points(t_points *points, double range)
{
	const double	height_scale = OBJ_HEIGHT / range;
	const double	width_scale = OBJ_WIDTH / range;
	size_t			i;
	t_vect			*vect;

	i = 0;
	while (i < points->size)
	{
		vect = &points->vects[i];
		vect->x *= width_scale;
		vect->y *= width_scale;
		vect->z *= height_scale;
		i++;
	}
}

void	scale_object_to_adjust_screen(t_points *points)
{
	double	range;
	t_vect	max;
	t_vect	min;

	get_max_value(points, &max);
	get_min_value(points, &min);
	range = get_max_range(&max, &min);
	scale_points(points, range);
}
