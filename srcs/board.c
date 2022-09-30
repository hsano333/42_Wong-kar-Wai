/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:02:05 by hsano             #+#    #+#             */
/*   Updated: 2022/09/30 23:08:06 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game2048.h"

void	test(t_game *game)
{
	game->board[0][0] = V2;
	game->board[0][1] = V4;
	game->board[0][2] = V8;
	game->board[0][3] = V16;
	game->board[0][4] = V32;

	game->board[1][0] = V64;
	game->board[1][1] = V128;
	game->board[1][2] = V256;
	game->board[1][3] = V512;
	game->board[1][4] = V1024;

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
	game->board[4][4] = V32;


}

int	get_two_or_four(void)
{
	int	value;

	value = rand();
	if (value > RAND_MAX * 0.8)
		return (V4);
	return (V2);
}

int	get_random_value(int max)
{
	return (rand() % max);
}

void	send_key_board(int key, t_game *game)
{

	test(game);
	if (key == KEY_UP)
		game->board[0][0] = get_two_or_four();
	else if (key == KEY_DOWN)
		game->board[0][0] = V8;
	else if (key == KEY_LEFT)
		game->board[0][0] = V16;
	else if (key == KEY_RIGHT)
		game->board[0][0] = V32;
	update_board(game);
	//refresh();
}
