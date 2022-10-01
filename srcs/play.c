/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:43:43 by hsano             #+#    #+#             */
/*   Updated: 2022/10/01 22:11:27 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game2048.h"
#include "unistd.h"

void	play(t_game *game)
{
	int	c;

	printw("score:%d, best score:%d\n", game->score, game->best_score[game->mode]);
	update_board(game);
	while (1)
	{
		if (game->end_flag)
			break ;
		else if ((c = getch()) != ERR) {
			if (c == ESC_KEY)
			{
				game->quit_flag = true;
				break ;
			}
			else if (c == KEY_UP || c == KEY_DOWN || c == KEY_LEFT || c == KEY_RIGHT)
			{
				clear();
				send_key_board(c, game);
				attron(COLOR_PAIR(1));
				if (game->win_flag)
				{
					printw("score:%d, best score:%d  ", game->score, game->max_score);
					attron(COLOR_PAIR(13));
					printw("victory\n");
				}
				else 
					printw("score:%d, best score:%d\n", game->score, game->max_score);
			}
			refresh();
		}
	}
}
