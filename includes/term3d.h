#ifndef TERM3D_H
# define TERM3D_H
# define SCREEN_SIZE		150
# define CAM_TO_SCREEN_DIST	150
# define SCALE_TO_INT		10
# include <stddef.h>
typedef struct s_vect t_vect;
typedef struct
{
	size_t	size;
	t_vect	*points;
}	t_points;

#endif
