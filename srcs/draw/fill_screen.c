#include <sys/types.h>
#include <string.h>
#include "draw.h"
#include "vector.h"
#include "term3d.h"

static bool	is_in_screen(double y, double z)
{
	return (-SCREEN_WIDTH / 2 < y && y < SCREEN_WIDTH / 2 && \
			-SCREEN_HEIGHT / 2 < z && z < SCREEN_HEIGHT / 2);
}

static void	fill_screen(t_screen screen, double y, double z)
{
	const ssize_t	offset_origin_h = SCREEN_HEIGHT / 2;
	const ssize_t	offset_origin_w = SCREEN_WIDTH / 2;
	const ssize_t	screen_y = y + offset_origin_w;
	const ssize_t	screen_z = z + offset_origin_h;

	screen[screen_z][screen_y]++;
}

void	fill_screen_with_points(t_screen screen, t_points *points)
{
	size_t	i;
	t_vect	*vect;

	i = 0;
	while (i < points->size)
	{
		vect = &points->vects[i];
		if (is_in_screen(vect->y, vect->z))
			fill_screen(screen, vect->y, vect->z);
		i++;
	}
}
