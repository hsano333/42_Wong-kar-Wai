/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:42:44 by hsano             #+#    #+#             */
/*   Updated: 2022/10/01 22:29:52 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game2048_bonus.h"

void	load_best_score(t_game *game)
{
	game_mode	mode;

	mode = mode4x4;
	while (mode <= mode5x5)
	{
		game->best_score[mode] = get_best_score(mode);
		mode++;
	}
}

int main(void)
{
	t_game	game;

	game.win = initscr();
	if (!init(&game))
	{
		printw("invalid win value");
		refresh();
		return (false);
	}
	//refresh();
	load_best_score(&game);
	while (!game.quit_flag)
	{
		menu(&game);
		clear_score(&game);
		init_board(&game);
		play(&game);
		if (game.score > game.best_score[game.mode])
			set_best_score(&game, game.score);
	}
	endwin();
}
