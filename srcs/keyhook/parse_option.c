#include <stdlib.h>
#include "ft_string.h"
#include "keyhook.h"

static void	set_rotate_speed(char key_input, t_option *option)
{
	if (ft_strchr("wasd ", key_input))
		option->rotate_speed = key_input;
}

static void	set_zoom_rate(char key_input, t_option *option)
{
	if (key_input == 'i' || key_input == 'o')
		option->zoom_rate = key_input;
}

static void	set_reset_flag(char key_input, t_option *option)
{
	if (key_input == 'r')
		option->reset = true;
}

void	parse_option(char key_input, t_option *option)
{
	*option = (t_option){};
	set_reset_flag(key_input, option);
	set_rotate_speed(key_input, option);
	set_zoom_rate(key_input, option);
}
