#ifndef OPTION_H
# define OPTION_H
typedef struct s_option
{
	bool	reset;
	char	rotate_speed;
	char	zoom_rate;
	char	shift_coordinate;
}	t_option;

void	get_reset_flag(char key_input, t_option *option);
void	get_rotate_speed(char key_input, t_option *option);
void	get_shift_coordinate(char key_input, t_option *option);
void	get_zoom_rate(char key_input, t_option *option);
void	option_handler(char key_input, t_option *option);

#endif
