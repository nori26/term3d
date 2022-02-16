#include <stdlib.h>
#include "term3d.h"
#include "input.h"
#include "vector.h"

int main(int argc, char **argv)
{
	size_t		i;
	t_vect		*vect;
	t_points	points;

	if (argc < 2)
		return (0);
	// points = input("/.3d");
	// points = input(".3d");
	// points = input("a/.3d");
	// points = input("3d");
	// points = input(".3d.");
	// points = input("..3d");
	points = input(argv[1]);
	i = 0;
	while (i < points.size)
	{
		vect = &points.points[i];
		vect_print(vect);
		i++;
	}
	free(points.points);
}
