#include <math.h>

#define PHI 0.02

double	get_angle_w_s(double angle, char option)
{
	double			abs;

	abs = fabs(angle);
	if (option == 's' && abs > 0)
		abs -= PHI;
	else if (option == 'w' && abs < 6.28)
		abs += PHI;
	if (angle > 0)
		angle = abs;
	else
		angle = abs * -1;
	return (angle);
}
