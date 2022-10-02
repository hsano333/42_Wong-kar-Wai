#include "game2048.h"

void	clear_score(t_game *game)
{
	game->score = 0;
	game->end_flag = false;
	if (game->win_value == V1 || game->win_value == V2)
		game->win_flag = true;
	else
		game->win_flag = false;
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
	add_new_number(game);
	add_new_number(game);
	check_board(game);
}

void	press_esc(t_game *game)
{
	attron(COLOR_PAIR(3));
	printw("\nquit game\n");
	game->quit_flag = true;
	refresh();
}
