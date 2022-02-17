#include "adjust.h"
#include "term3d.h"
#include "vector.h"

void	adjust_object_to_screen(t_points *points)
{
	shift_to_center(points);
	scale_object_to_adjust_screen(points);
}
