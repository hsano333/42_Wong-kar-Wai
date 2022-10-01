#include "game2048.h"

static bool	check_board_win(t_game *game, int i, int j)
{
	if (game->board[i][j] == V2048)
	{
		/* end_falg */
		return (true);
	}
	if (game->board[i][j] == game->win_value)
	{
		// win_flag
		return (true);
	}
	else
		return (false);
}

static bool	check_board_empty(t_game *game, int i, int j)
{
	if (!game->board[i][j])
		return (true);
	else
		return (false);
}

static bool	check_board_mergeable(t_game *game, int i, int j)
{
	if ((i != game->grid_row_size - 1 && game->board[i][j] == game->board[i + 1][j])
		|| (j != game->grid_col_size - 1 && game->board[i][j] == game->board[i][j + 1]))
		return (true);
	else
		return (false);
}

static int	check_board_roop(t_game *game, bool (*f)(t_game *, int, int))
{
	for (int i = 0; i < game->grid_row_size; i ++)
	{
		for (int j = 0; j < game->grid_col_size; j ++)
		{
			if (f(game, i, j))
				return (true);
		}
	}
	return (false);
}

int	check_board(t_game *game)
{
	if (check_board_roop(game, check_board_win))
		return (0);
	else if (check_board_roop(game, check_board_empty))
		return (1);
	else if (check_board_roop(game, check_board_mergeable))
		return (2);
	else
	{
		// end_flag
		return (3);
	}
}