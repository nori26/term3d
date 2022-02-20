#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include "keyhook.h"
#include "wrapper.h"

static const t_default_setting	*default_setting_holder(void)
{
	static bool					is_init = true;
	static t_default_setting	settings;

	if (is_init)
	{
		ft_tcgetattr(STDIN_FILENO, &settings.term);
		settings.fcntl = ft_fcntl(STDIN_FILENO, F_GETFL, 0);
		is_init = false;
	}
	return (&settings);
}

static void	set_non_blocking_stdin(void)
{
	const t_default_setting	*default_settings;
	struct termios			settings;

	default_settings = default_setting_holder();
	settings = default_settings->term;
	settings.c_lflag &= ~(ECHO | ICANON);
	ft_tcsetattr(STDIN_FILENO, TCSANOW, &settings);
	ft_fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}

static void	reset_stdin(void)
{
	const t_default_setting	*default_settings;

	default_settings = default_setting_holder();
	ft_tcsetattr(STDIN_FILENO, TCSANOW, &default_settings->term);
	ft_fcntl(STDIN_FILENO, F_SETFL, default_settings->fcntl);
}

char	getchar_non_blocking(void)
{
	int	key_input;

	set_non_blocking_stdin();
	key_input = getchar();
	reset_stdin();
	return (key_input);
}
