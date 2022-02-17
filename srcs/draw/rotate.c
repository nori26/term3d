#include <stdbool.h>
#include "vector.h"
#include "term3d.h"

#define PHI			0.02

static double	rotation_angle_storage(double set_angle, bool is_set)
{
	static double	angle = PHI;

	if (is_set)
		angle = set_angle;
	return (angle);
}

void	reset_rotation_angle(void)
{
	rotation_angle_storage(PHI, true);
}

double	get_rotation_angle(void)
{
	return (rotation_angle_storage(0, false));
}

void	set_rotation_angle(char option)
{
	static double	prev = PHI;
	double			angle;

	angle = get_rotation_angle();
	if (option == 's' && angle > 0)
		angle -= PHI;
	else if (option == 'w' && angle < 6.28)
		angle += PHI;
	else if (option == ' ')
	{
		if (angle)
		{
			prev = get_rotation_angle();
			angle = 0;
		}
		else
			angle = prev;
	}
	else if (option == 'a' && angle > 0)
		angle = -angle;
	else if (option == 'd' && angle < 0)
		angle = -angle;
	rotation_angle_storage(angle, true);
}

void	rotate_z(t_points *points)
{
	size_t	i;
	t_vect	*vect;
	double	theta;

	theta = get_rotation_angle();
	i = 0;
	while (i < points->size)
	{
		vect = &points->vects[i];
		rotate_matrix_z(&vect->x, &vect->y, theta);
		i++;
	}
}
