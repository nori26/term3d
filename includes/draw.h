#ifndef DRAW_H
# define DRAW_H
# include <stdbool.h>
# define SCREEN_HEIGHT	50
# define SCREEN_WIDTH	65
typedef struct s_points	t_points;
typedef struct s_option	t_option;
typedef size_t			t_screen[SCREEN_HEIGHT][SCREEN_WIDTH];

_Noreturn void	draw(t_points *points);
double			get_rotation_angle();
t_points		create_points_copy(t_points *points);
void			alter_coordinate(t_points *points, t_points *base, t_option *option);
void			draw_object(t_points *points);
void			fill_screen_with_points(t_screen screen, t_points *points);
void			print_screen(t_screen screen);
void			reset_coordinate(t_points *points, t_points *base);
void			reset_rotation_angle(void);
void			rotate_z(t_points *points);
void			set_rotation_angle(char option);

#endif
