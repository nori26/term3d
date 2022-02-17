#ifndef DRAW_H
# define DRAW_H
# include <stdbool.h>
# define SCREEN_HEIGHT	50
# define SCREEN_WIDTH	65
typedef struct s_points	t_points;
typedef struct s_option	t_option;
typedef size_t			t_screen[SCREEN_HEIGHT][SCREEN_WIDTH];

_Noreturn void	draw(t_points *points);
double			get_rotation_angle(void);
void			fill_screen_with_points(t_screen screen, t_points *points);
void			init_screen(t_screen screen);
void			print_screen(t_screen screen);
void			reset_rotation_angle(void);
void			rotate_z(t_points *points);
void			set_rotation_angle(char option);
void			zoom_object(char option, t_points *points);

#endif
