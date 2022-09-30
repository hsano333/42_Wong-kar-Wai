/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_borad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:32:23 by hsano             #+#    #+#             */
/*   Updated: 2022/09/30 21:02:32 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game2048.h"
#include "numbers.h"

static void	set_frame(t_game *game, char *line)
{
	line[0] = '|';
	line[41] = '|';
	line[82] = '|';
	line[123] = '|';
	line[164] = '|';
	line[205] = '|';
	if (game->grid_col_size == 5)
		line[206] = '\0';
	else
		line[165] = '\0';
}

void	print_row_line(t_game *game)
{
	char line[256] = "+----------------------------------------+----------------------------------------+----------------------------------------+----------------------------------------+----------------------------------------+";

	if (game->grid_col_size == 5)
		line[206] = '\0';
	else
		line[165] = '\0';
	printw("%s\n", line);
}

void	get_aa_number_wrapper(int row, char *line, int number)
{
	int	i;

	i = 0;
	while (i < 40)
		line[i++] = ' ';
	//if (number == 0)
		//get_aa_zero(row, line);
	if (number == V2)
		get_aa_str2(row, line);
	else if (number == V4)
		get_aa_str4(row, line);
	else if (number == V8)
		get_aa_str8(row, line);
	else if (number == V16)
		get_aa_str16(row, line);
	else if (number == V32)
		get_aa_str32(row, line);
	else if (number == V64)
		get_aa_str64(row, line);
	else if (number == V128)
		get_aa_str128(row, line);
	else if (number == V256)
		get_aa_str256(row, line);
	else if (number == V512)
		get_aa_str512(row, line);
	else if (number == V1024)
		get_aa_str1024(row, line);
	else if (number == V2048)
		get_aa_str2048(row, line);
	else if (number == V4096)
		get_aa_str4096(row, line);
	else if (number == V8192)
		get_aa_str8192(row, line);
	else if (number == V16384)
		get_aa_str16384(row, line);
	else if (number == V32768)
		get_aa_str32768(row, line);
	else if (number == V65536)
		get_aa_str65536(row, line);
}

void	update_board(t_game *game)
{
	char	line[256];
	int		row;
	int		frame_row;
	int		row_max;

	//clear();
	//printw("test \n");
	//printw("game:%p\n", game);
	//
	//
	game->board[0][0] = V2;
	game->board[0][1] = V4;
	game->board[0][2] = V8;
	game->board[0][3] = V16;
	game->board[0][4] = V32;

	game->board[1][0] = V64;
	game->board[1][1] = V128;
	game->board[1][2] = V256;
	game->board[1][3] = V512;
	game->board[1][4] = V1024;

	game->board[2][0] = V2048;
	game->board[2][1] = V4096;
	game->board[2][2] = V8192;
	game->board[2][3] = V16384;
	game->board[2][4] = V32768;

	game->board[3][0] = V65536;
	game->board[3][1] = V4096;
	game->board[3][2] = V8192;
	game->board[3][3] = V16384;
	game->board[3][4] = V32768;

	game->board[4][0] = V2;
	game->board[4][1] = V4;
	game->board[4][2] = V8;
	game->board[4][3] = V16;
	game->board[4][4] = V32;
	
	row = 0;
	row_max = AA_SIZE;
	if (game->grid_col_size == 5)
		row_max = AA_SIZE;
	while (row < game->grid_row_size)
	{
		print_row_line(game);
		frame_row = 0;
		while (frame_row < AA_SIZE)
		{
			get_aa_number_wrapper(frame_row, &line[1], game->board[row][0]);
			get_aa_number_wrapper(frame_row, &line[42], game->board[row][1]);
			get_aa_number_wrapper(frame_row, &line[83], game->board[row][2]);
			get_aa_number_wrapper(frame_row, &line[124], game->board[row][3]);
			get_aa_number_wrapper(frame_row, &line[165], game->board[row][4]);
			set_frame(game, line);
			printw("%s\n", line);
			frame_row++;
		}
		row++;
	}
	print_row_line(game);
	refresh();
}
