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

void test2(t_game *game)
{
	game->board[0][0] = V16;
	game->board[0][1] = V64;
	game->board[0][2] = V32;
	game->board[0][3] = V8;

	game->board[1][0] = V4;
	game->board[1][1] = V32;
	game->board[1][2] = V16;
	game->board[1][3] = V128;

	game->board[2][0] = V2;
	game->board[2][1] = V16;
	game->board[2][2] = V32;
	game->board[2][3] = V4;

	game->board[3][0] = V4;
	game->board[3][1] = V8;
	game->board[3][2] = V4;
	game->board[3][3] = V2;


}
void test3(t_game *game)
{
	game->board[0][0] = V4;
	game->board[0][1] = V16;
	game->board[0][2] = V32;
	game->board[0][3] = V8;

	game->board[1][0] = V32;
	game->board[1][1] = V256;
	game->board[1][2] = V16;
	game->board[1][3] = V4;

	game->board[2][0] = V4;
	game->board[2][1] = V16;
	game->board[2][2] = V8;
	game->board[2][3] = V2;

	game->board[3][0] = V2;
	game->board[3][1] = V4;
	game->board[3][2] = V2;
	game->board[3][3] = V4;


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
	//refresh();
	load_best_score(&game);
	while (!game.quit_flag)
	{
		menu(&game);
		if (game.quit_flag)
			break ;
		clear_score(&game);
		init_board(&game);
		//test3(&game);
		play(&game);
		if (game.score > game.best_score[game.mode])
			game.best_score[game.mode] = game.score;
	}
	endwin();
}
