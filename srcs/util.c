#include "game2048.h"

void	clear_score(t_game *game)
{
	game->score = 0;
	game->end_flag = false;
}

void	clear_board(t_game *game)
{
	for (int i = 0; i < 5; i ++)
		for (int j = 0; j < 5; j ++)
			game->board[i][j] = 0; // test
}

int	have_four(t_game *game)
{
	if (game->win_value != V4)
		return (false);
	for (int i = 0; i < 5; i ++)
		for (int j = 0; j < 5; j ++)
			if (game->board[i][j] == V4)
				return (true);
	return (false);
}

void	init_board(t_game *game)
{
	clear_board(game);
	add_new_number(game);
	add_new_number(game);
	check_board(game);
}

void	init_game(t_game *game)
{
		clear_score(game);
		init_board(game);
}

void	press_esc(t_game *game)
{
	attron(COLOR_PAIR(3));
	printw("\nquit game\n");
	game->quit_flag = true;
	refresh();
}
