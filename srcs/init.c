/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiyu <smiyu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:05:06 by hsano             #+#    #+#             */
/*   Updated: 2022/10/01 17:51:13 by smiyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game2048.h"

void set_timeout(int time) {
	time = 1;
	timeout(1);
	(void)time;
}

static void	init_board(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			game->board[i][j] = 0;
			j ++;
		}
		i ++;
	}
}

static void	init_color_pair(void)
{


	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(8, COLOR_MAGENTA, COLOR_CYAN);
	init_pair(9, COLOR_GREEN, COLOR_MAGENTA);
	init_pair(10, COLOR_BLUE, COLOR_GREEN);
	init_pair(11, COLOR_RED, COLOR_BLUE);
	init_pair(12, COLOR_YELLOW, COLOR_RED);
	//bkgd(3);
	//attrset(2);
	attron(COLOR_PAIR(4));

	if (has_colors())
		printw("color OK\n");
	else
		printw("color NG\n");

}

int	check_win_value(void)
{
	int	number;

	number = WIN_VALUE;
	if (number == V2)
		return (true);
	else if (number == V4)
		return (true);
	else if (number == V8)
		return (true);
	else if (number == V16)
		return (true);
	else if (number == V32)
		return (true);
	else if (number == V64)
		return (true);
	else if (number == V128)
		return (true);
	else if (number == V256)
		return (true);
	else if (number == V512)
		return (true);
	else if (number == V1024)
		return (true);
	else if (number == V2048)
		return (true);
	return (false);
}

int	init(t_game *game)
{
	int	height;
	int	width;

	if (!check_win_value())
		return (false);
	game->score = 0;
	init_board(game);
	init_color_pair();
	height = 0;
	width = 0;
	srand(time(0));
	set_timeout(1);
	timeout(1);
	start_color();
	getmaxyx(game->win, height, width);
	keypad(game->win, TRUE);
	printf("height=%d, width=%d\n", height, width);
	return (true);
}
