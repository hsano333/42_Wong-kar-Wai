/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiyu <smiyu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:11:35 by hsano             #+#    #+#             */
/*   Updated: 2022/10/01 15:09:21 by smiyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game2048.h"
#include "unistd.h"

void	test(t_game *game)
{
	for (int i = 0; i < 5; i ++)
		for (int j = 0; j < 5; j ++)
			game->board[i][j] = 0;
	// game->board[0][1] = V2;
	// game->board[2][2] = V2;

	game->board[0][0] = V2;
	game->board[1][0] = V2;
	game->board[2][0] = V4;
	game->board[3][0] = V8;
	// game->board[1][4] = V16;

	game->board[0][1] = V8;
	game->board[1][1] = V4;
	game->board[2][1] = V2;
	game->board[3][1] = V2;
	// game->board[1][4] = V1024;

	/*
	game->board[2][0] = V2048;
	game->board[2][1] = V4096;
	game->board[2][2] = V8192;
	game->board[2][3] = V16384;
	game->board[2][4] = V32768;

	game->board[3][0] = V65536;
	game->board[3][1] = V4096;
	game->board[3][2] = V8192;
	game->board[3][3] = V16384;
	game->board[3][4] = V32768;

	game->board[4][0] = V2;
	game->board[4][1] = V4;
	game->board[4][2] = V8;
	game->board[4][3] = V16;
	game->board[4][4] = 0;
	*/
}


int main(void)
{
	t_game	game;

	game.win = initscr();
	if (!init(&game))
	{
		printf("invalid win value");
		return (false);
	}
	refresh();
	usleep(1000000);

	menu(&game);
	test(&game);
	//printw("%s\n", two[8]);
	printw("update board \n");
	update_board(&game);
	refresh();
	usleep(1000000);

	play(&game);

	endwin();
}
