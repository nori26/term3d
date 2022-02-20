#include <stdlib.h>
#include <termios.h>
#include "wrapper.h"

int	ft_tcsetattr(int fd, int optional_actions, const struct termios *termios_p)
{
	if (tcsetattr(fd, optional_actions, termios_p) == SYS_ERR)
	{
		perror("tcsetattr");
		exit(EXIT_FAILURE);
	};
	return (SYS_OK);
}
