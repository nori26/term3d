#ifndef TERM3D_H
# define TERM3D_H
# define SCREEN_HEIGHT		48
# define SCREEN_WIDTH		63
# define OBJ_HEIGHT			45
# define OBJ_WIDTH			60
# define PHI				0.02
# include <stddef.h>
typedef struct s_vect	t_vect;
typedef struct
{
	size_t	size;
	t_vect	*points;
}	t_points;

#endif
