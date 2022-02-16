#ifndef TERM3D_H
# define TERM3D_H
# define SCREEN_HEIGHT		50
# define SCREEN_WIDTH		65
# define OBJ_HEIGHT			45
# define OBJ_WIDTH			60
# define PHI				0.02
# include <stddef.h>
# include "vector.h"
typedef struct s_points
{
	size_t	size;
	t_vect	*points;
}	t_points;

#endif
