#ifndef DRAW_H
# define DRAW_H
# include <stdbool.h>
# define SCREEN_HEIGHT	50
# define SCREEN_WIDTH	65
typedef struct s_points	t_points;
typedef size_t			t_screen[SCREEN_HEIGHT][SCREEN_WIDTH];

_Noreturn void	draw_object(t_points *points);
void			fill_screen_with_points(t_screen screen, t_points *points);

#endif
