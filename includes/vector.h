#ifndef VECTOR_H
# define VECTOR_H
typedef struct s_vect
{
	double	x;
	double	y;
	double	z;
}	t_vect;

double	dot(t_vect v1, t_vect v2);
double	vect_len(t_vect v);
t_vect	cross(t_vect v1, t_vect v2);
t_vect	vect_add(t_vect v1, t_vect v2);
t_vect	vect_init(double x, double y, double z);
t_vect	vect_mult(t_vect v, double d);
t_vect	vect_sub(t_vect v1, t_vect v2);
t_vect	vect_unit(t_vect v);
void	rotate_matrix_z(double *x, double *y, double angle);
void	vect_print(t_vect *vect);

#endif
