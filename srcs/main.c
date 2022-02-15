#include "term3d.h"
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#define PI 3.141592653589793
#define FOV	60
#define SCREEN_SIZE 150

void	print(bool screen[SCREEN_SIZE][SCREEN_SIZE])
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < SCREEN_SIZE)
	{
		x = 0;
		while (x < SCREEN_SIZE)
		{
			if (screen[y][x])
				printf(".");
			else
				printf(" ");
			x++;
		}
		puts("");
		y++;
	}
}


int	main()
{
	FILE	*file;
	t_vect	p;
	t_vect	unit;
	ssize_t	offset = SCREEN_SIZE / 2;
	const double	cam_to_screen = SCREEN_SIZE;
	double	x = 1.544456534909866;
	double	y = 2.5718969675658103;
	double	z = 5;
	bool	screen[SCREEN_SIZE][SCREEN_SIZE] = {};
	char *line;
	char *tmp;
	size_t	n = 0;

	x *= 10 - cam_to_screen;
	y *= 10;
	z *= 10;
	file = fopen("torus.3d", "r");
	line = NULL;

	while (getline(&line, &n, file) != -1)
	{
		tmp = line;
		x = atof(strsep(&tmp, ",")) * 10  - cam_to_screen;
		y = atof(strsep(&tmp, ",")) * 10;
		z = atof(strsep(&tmp, ",")) * 10;
		p = vect_init(x, y, z);
		unit = vect_unit(p);
		p = vect_mult(unit, cam_to_screen);
		if (p.y < SCREEN_SIZE / 2 && p.z < SCREEN_SIZE / 2)
			screen[(ssize_t)p.z + offset][(ssize_t)p.y + offset] = true;
		free(line);
		line = NULL;
	}
	print(screen);
	printf("%f %f", p.y, p.z);

}
