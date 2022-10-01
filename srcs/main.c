#include "game2048.h"
#include "unistd.h"

void	test(t_game *game)
{
	game->board[0][1] = V2;
	game->board[2][2] = V2;
}


void	load_best_score(t_game *game)
{
	game_mode	mode;

	mode = mode4x4;
	while (mode <= mode5x5)
	{
		game->best_score[mode] = 0;
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
			game.best_score[game.mode] = game.score;
	}
	endwin();
}
