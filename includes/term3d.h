#ifndef TERM3D_H
# define TERM3D_H
# define OBJ_HEIGHT			45
# define OBJ_WIDTH			60
# define PHI				0.02
# include <stddef.h>

typedef struct s_vect	t_vect;
typedef struct s_points
{
	size_t	size;
	t_vect	*vects;
}	t_points;

#endif
