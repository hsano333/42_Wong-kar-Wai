#include "game2048.h"
#include "unistd.h"

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
		attron(COLOR_PAIR(3));
		printw("invalid win value");
		refresh();
		return (false);
	}
	load_best_score(&game);
	while (!game.quit_flag)
	{
		menu(&game);
		if (game.quit_flag)
			break ;
		init_game(&game);
		play(&game);
		if (game.score > game.best_score[game.mode])
			game.best_score[game.mode] = game.score;
	}
	endwin();
}
