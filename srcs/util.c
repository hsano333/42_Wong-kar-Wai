#include "game2048.h"

void	clear_score(t_game *game)
{
	game->score = 0;
	game->win_flag = false;
	game->end_flag = false;
}

void	clear_board(t_game *game)
{
	for (int i = 0; i < 5; i ++)
		for (int j = 0; j < 5; j ++)
			game->board[i][j] = 0; // test
}


void	init_board(t_game *game)
{
	clear_board(game);
	for (int i = 0; i < 5; i ++)
		game->board[3][i] = 2;
	//add_new_number(game);
	//add_new_number(game);
}

void	press_esc(t_game *game)
{
	attron(COLOR_PAIR(3));
	printw("\nquit game\n");
	game->quit_flag = true;
	refresh();
}
