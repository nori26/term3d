/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:27:09 by user42            #+#    #+#             */
/*   Updated: 2022/02/19 04:06:50 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
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

void	set_non_blocking_stdin(void)
{
	struct termios	settings;

	tcgetattr(STDIN_FILENO, &settings);
	settings.c_lflag &= ~(ECHO | ICANON);
	settings.c_cc[VTIME] = 0;
	settings.c_cc[VMIN] = 1;
	tcsetattr(STDIN_FILENO, TCSANOW, &settings);
	fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
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
	set_non_blocking_stdin();
	points = read_points_from_file(argv[1]);
	adjust_object_to_screen(&points);
	draw(&points);
}
