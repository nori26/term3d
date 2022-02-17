#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "ft_list.h"
#include "term3d.h"
#include "adjust.h"
#include "input.h"
#include "draw.h"

void	validate_terminal_size(void)
{
	struct winsize	ws;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1)
	{
		perror("ioctl");
		exit(EXIT_FAILURE);
	}
	if (ws.ws_col < SCREEN_WIDTH)
	{
		fprintf(stderr, "terminal width not enough");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_points	points;

	if (argc != 2)
	{
		fprintf(stderr, "invalid argument");
		exit(EXIT_FAILURE);
	}
	validate_terminal_size();
	points = input(argv[1]);
	adjust_object_to_screen(&points);
	draw_object(&points);
	free(points.vects);
}
