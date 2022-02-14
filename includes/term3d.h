#ifndef TERM3D_H
# define TERM3D_H
typedef struct
{
	double	x;
	double	y;
	double	z;
}			t_vect;

double	dot(t_vect v1, t_vect v2);
double	vect_len(t_vect v);
int		check_parallel(t_vect a, t_vect b, t_vect c);
t_vect	cross(t_vect v1, t_vect v2);
t_vect	vect_add(t_vect v1, t_vect v2);
t_vect	vect_init(double x, double y, double z);
t_vect	vect_mult(t_vect v, double d);
t_vect	vect_sub(t_vect v1, t_vect v2);
t_vect	vect_unit(t_vect v);

#endif
