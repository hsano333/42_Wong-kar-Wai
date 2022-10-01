/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiyu <smiyu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:02:05 by hsano             #+#    #+#             */
/*   Updated: 2022/10/01 19:42:31 by smiyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game2048.h"

/*
	board[row][col]
	row = 縦
	col = 横
*/

static int	get_two_or_four(void)
{
	int	value;

	value = rand();
	if (value > RAND_MAX * 0.8)
		return (V4);
	return (V2);
}

static int	get_random_value(int max)
{
	return (rand() % max);
}

static void	add_new_number(t_game *game)
{
	int	*square;

	square = &game->board[get_random_value(game->grid_row_size)][get_random_value(game->grid_col_size)];
	if (!*square)
		*square = get_two_or_four();
	else
		add_new_number(game);
}

static bool	plus_next(int *now, int *next, bool front)
{
	if (*now == *next && !front)
	{
		*next *= 2;
		*now = 0;
		return (true);
	}
	return (false);
}

static bool	line_up_properly(int *now, int *next, bool front)
{
	(void)front;
	if (*now && !*next)
	{
		*next = *now;
		*now = 0;
		return (true);
	}
	return (false);
}

static void	board_roop(const int start, const int end, const int dir, t_game *game, bool (*f)(int *, int *, bool))
{
	int			i[2];
	int			i_end[2];
	int			*now;
	int			*next;
	bool		front;
	const int	sign = (start < end) * 2 - 1; 

	i[0] = 0;
	i_end[0] = game->grid_row_size * dir + game->grid_col_size * !dir;
	while (i[0] < i_end[0])
	{
		i[1] = start;
		i_end[1] = end;
		front = false;
		while (i[1] != i_end[1])
		{
			// printw("now:board[%d][%d]=%d, ", i[!dir], i[dir], game->board[i[!dir]][i[dir]]);
			// printw("now:board[%d][%d]=%d\n", i[!dir] + sign * !dir, i[dir] + sign * dir, game->board[i[!dir] + sign * !dir][i[dir] + sign * dir]);
			now = &game->board[i[!dir]][i[dir]];
			next = &game->board[i[!dir] + sign * !dir][i[dir] + sign * dir];
			front = f(now, next, front);
			i[1] += sign;
		}
		i[0] ++;
	}
}

static void	move_board_number(const int start, const int end, const int dir, t_game *game)
{
	int	i;

	i = 0;
	while (i++ < 4)
		board_roop(end, start, dir, game, line_up_properly);
	board_roop(start, end, dir, game, plus_next);
	i = 0;
	while (i++ < 4)
		board_roop(end, start, dir, game, line_up_properly);
}

void	send_key_board(int key, t_game *game)
{
	// int	status;

	if (key == KEY_UP)
		move_board_number(0, game->grid_row_size - 1, 0, game);
	else if (key == KEY_DOWN)
		move_board_number(game->grid_row_size - 1, 0, 0, game);
	else if (key == KEY_LEFT)
		move_board_number(0, game->grid_col_size - 1, 1, game);
	else if (key == KEY_RIGHT)
		move_board_number(game->grid_col_size - 1, 0, 1, game);
	// status = check_board(game);
	// if (/* status == 0 && !end_flag || */ status == 1)
		add_new_number(game);
	update_board(game);
	//refresh();
}