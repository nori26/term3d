#ifndef KEYHOOK_H
# define KEYHOOK_H
# include <stdbool.h>
typedef struct s_option
{
	bool	reset;
	char	rotate_speed;
	char	zoom_rate;
}	t_option;

void	hook_key_input(t_option *option);
void	parse_option(char key_input, t_option *option);

#endif
