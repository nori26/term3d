#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "ft_list.h"
#include "parse.h"
#include "term3d.h"
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
		fprintf(stderr, "terminal width too short");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_points	points;
	t_clist		*lines;

	if (argc != 2)
	{
		fprintf(stderr, "invalid argument");
		exit(EXIT_FAILURE);
	}
	validate_terminal_size();
	lines = input(argv[1]);
	points = parse_lines_to_points(lines);
	ft_clst_clear(&lines, free);
	draw_object(&points);
	free(points.points);
}
