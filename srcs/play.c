/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:43:43 by hsano             #+#    #+#             */
/*   Updated: 2022/10/01 13:50:33 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game2048.h"
#include "unistd.h"

void	play(t_game *game)
{
	int	c;

	printf("game:%p\n", game);
	while (1)
	{
		if ((c = getch()) != ERR) {
			clear();
			if (c == ESC_KEY)
				break ;
			else if (c == KEY_UP || c == KEY_DOWN || c == KEY_LEFT || c == KEY_RIGHT)
			{
				attron(COLOR_PAIR(1));
				if (game->win_flag)
				{
					printw("score=%d  ", game->score);
					attron(COLOR_PAIR(13));
					printw("victory\n");
				}
				else 
					printw("score=%d\n", game->score);
				send_key_board(c, game);
			}
			printw("%d\n", c);
			refresh();
		}
		usleep(1000);
	}
}
