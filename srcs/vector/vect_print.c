#include <stdio.h>
#include "vector.h"

void	vect_print(t_vect *vect)
{
	printf("%.15g,%.15g,%.15g\n", vect->x, vect->y, vect->z);
}
