#ifndef TERM3D_H
# define TERM3D_H
# define SCREEN_HEIGHT		45
# define SCREEN_WIDTH		60
# define OBJ_HEIGHT			42
# define OBJ_WIDTH			57
# define SCREEN_SIZE		60
# define CAM_TO_SCREEN_DIST	60
# define SCALE_TO_INT		10
# include <stddef.h>
typedef struct s_vect t_vect;
typedef struct
{
	size_t	size;
	t_vect	*points;
}	t_points;

#endif
