#include <stdio.h>
#include "vector.h"

void	vect_print(t_vect *vect)
{
	printf("%f,%f,%f\n", vect->x, vect->y, vect->z);
}
