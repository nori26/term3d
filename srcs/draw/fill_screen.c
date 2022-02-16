#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <math.h>
#include "draw.h"
#include "ft_list.h"
#include "parse.h"
#include "vector.h"
#include "term3d.h"
#include "input.h"

char	get_screen_char(size_t density)
{
	const char		*set = " :;=co+xanm.";
	const size_t	size = strlen(set);
	size_t			idx;

	if (density >= size)
		idx = size - 1;
	else
		idx = density;
	return (set[idx]);
}

bool	is_in_screen(ssize_t y, ssize_t z)
{
	return (-SCREEN_WIDTH / 2 < y && y < SCREEN_WIDTH / 2 && \
			-SCREEN_HEIGHT / 2 < z && z < SCREEN_HEIGHT / 2);
}

void	fill_screen(t_screen screen, ssize_t y, ssize_t z)
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
