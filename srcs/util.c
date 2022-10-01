#include "game2048.h"

void	clear_board(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 5)
		while (j < 5)
			game->board[i++][j++] = 0; // test
}
