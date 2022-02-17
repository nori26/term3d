#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include "draw.h"
#include "vector.h"
#include "term3d.h"
#include "option.h"

#include "utils.h"
#include <stdlib.h>
#include <math.h>

void	zoom_in(t_points *points)
{
	size_t	i;
	t_vect	*vect;
	double	scale;

	scale = 1.1;
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

void	zoom_out(t_points *points)
{
	size_t	i;
	t_vect	*vect;
	double	scale;

	scale = 0.9;
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

void	zoom_object(char option, t_points *points)
{
	if (option == 'i')
		zoom_in(points);
	else if (option == 'o')
		zoom_out(points);
}
