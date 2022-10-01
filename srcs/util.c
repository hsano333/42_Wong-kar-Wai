#include "game2048.h"

void	clear_board(t_game *game)
{
	for (int i = 0; i < 5; i ++)
		for (int j = 0; j < 5; j ++)
			game->board[i][j] = 0; // test
}
