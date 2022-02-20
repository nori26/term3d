#include <stdlib.h>
#include <fcntl.h>
#include "wrapper.h"

int	ft_fcntl(int fd, int cmd, int flag)
{
	int	ret;

	if (cmd == F_GETFL)
		ret = fcntl(fd, cmd);
	else
		ret = fcntl(fd, cmd, flag);
	if (ret == SYS_ERR)
	{
		perror("fcntl");
		exit(EXIT_FAILURE);
	}
	return (ret);
}
