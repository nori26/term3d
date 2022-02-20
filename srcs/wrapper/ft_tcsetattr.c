#include <termios.h>
#include <stdlib.h>
#include "wrapper.h"

int	ft_tcgetattr(int fd, struct termios *termios_p)
{
	if (tcgetattr(fd, termios_p) == SYS_ERR)
	{
		perror("tcgetattr");
		exit(EXIT_FAILURE);
	};
	return (SYS_OK);
}
