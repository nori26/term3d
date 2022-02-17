#ifndef DRAW_H
# define DRAW_H
# include <stdbool.h>
# define SCREEN_HEIGHT	50
# define SCREEN_WIDTH	65
typedef struct s_points	t_points;
typedef size_t			t_screen[SCREEN_HEIGHT][SCREEN_WIDTH];

_Noreturn void	draw_object(t_points *points);
double			get_rotation_angle();
double			rotation_angle_storage(double set_angle, bool is_set);
t_points		create_points_copy(t_points *points);
void			alter_coordinate(t_points *points, const t_points *base);
void			fill_screen_with_points(t_screen screen, t_points *points);
void			reset_coordinate(t_points *points, const t_points *base);
void			reset_rotation_angle(double set_angle, bool is_set);
void			set_rotation_angle(char option);
void			zoom_object(char option, t_points *points);

#endif
