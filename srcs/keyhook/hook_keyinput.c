#include <stdlib.h>
#include <stdio.h>
#include "keyhook.h"

void	hook_key_input(t_option *option)
{
	char			key_input;

	key_input = getchar();
	if (key_input == 'q')
		exit(EXIT_SUCCESS);
	parse_option(key_input, option);
}
