/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:02:05 by hsano             #+#    #+#             */
/*   Updated: 2022/10/01 00:04:42 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game2048.h"


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
