/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:43:43 by hsano             #+#    #+#             */
/*   Updated: 2022/10/02 17:16:14 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game2048.h"
#include "unistd.h"


void	print_score(t_game *game)
{
	attron(COLOR_PAIR(1));
	if (game->win_flag)
	{
		printw("score:%d, best score:%d  ", game->score, game->best_score[game->mode]);
		attron(COLOR_PAIR(13));
		printw("victory\n");
	}
	else 
		printw("score:%d, best score:%d\n", game->score, game->best_score[game->mode]);
	attron(COLOR_PAIR(1));
}

static void	print_game_over(t_game *game)
{

	clear();
	update_board(game);
	print_score(game);
	if (game->win_flag)
	{
		attron(COLOR_PAIR(7));
		printw("\ngame clear\n");
	}
	else
	{
		attron(COLOR_PAIR(3));
		printw("\ngame over\n");
	}
	attron(COLOR_PAIR(1));
	printw("Press Enter, so back to Menu\n");
}

void	game_over(t_game *game)
{
	int	c;

	print_game_over(game);
	while (1)
	{
		if ((c = getch()) != ERR) 
		{
			print_game_over(game);
			if (c == ESC_KEY) {
				press_esc(game);
				break ;
			}
			else if (c == ENTER_KEY)
				break ;
		}
	}
}

void	play(t_game *game)
{
	int	c;

	update_board(game);
	print_score(game);
	while (1)
	{
		if ((c = getch()) != ERR) 
		{
			clear();
			update_board(game);
			print_score(game);
			if (c == ESC_KEY)
			{
				press_esc(game);
				break ;
			}
			else if (c == KEY_UP || c == KEY_DOWN || c == KEY_LEFT || c == KEY_RIGHT)
			{
				clear();
				send_key_board(c, game);
				print_score(game);
			}
			refresh();
			if (game->end_flag) {
				game_over(game);
				break ;
			}
		}
	}
}
