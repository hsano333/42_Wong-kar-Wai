/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:18:06 by hsano             #+#    #+#             */
/*   Updated: 2022/10/02 01:24:34 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game2048.h"


static void	print_selected_mode(int color, char *str)
{

	attron(COLOR_PAIR(1));
	printw("                                                                                  ");
	attron(COLOR_PAIR(color));
	printw("%s\n", str);
	attron(COLOR_PAIR(1));
}

static void	print_menu(t_game *game, game_mode mode)
{
	int	frame_row;
	int	row;

	frame_row = 0;
	row = 2;

	clear();
	while (frame_row < AA_SIZE)
	{
		print_one_frame_line(game, row, frame_row, false);
		frame_row++;
	}
	printw("\n\n                                                                                  select mode and press Enter\n");

	if (mode == mode4x4)
		print_selected_mode(14, "mode 4x4");
	else
		print_selected_mode(1, "mode 4x4");
	if (mode == mode4x5)
		print_selected_mode(14, "mode 4x5");
	else
		print_selected_mode(1, "mode 4x5");
	if (mode == mode5x4)
		print_selected_mode(14, "mode 5x4");
	else
		print_selected_mode(1, "mode 5x4");
	if (mode == mode5x5)
		print_selected_mode(14, "mode 5x5");
	else
		print_selected_mode(1, "mode 5x5");
	refresh();
}

static game_mode	select_mode(game_mode now_mode, int key)
{
	game_mode mode;

	mode = now_mode;
	if (key == KEY_UP && now_mode == mode4x4)
		mode = now_mode;
	else if (key == KEY_DOWN && now_mode == mode5x5)
		mode = now_mode;
	else if (key == KEY_UP)
		mode = now_mode - 1;
	else if (key == KEY_DOWN)
		mode = now_mode + 1;
	return (mode);
}

void menu(t_game *game)
{
	game_mode	mode;
	t_game	tmp_game;
	int	c;
	
	clear_board(&tmp_game);
	tmp_game.board[2][2] = V2048MENU;
	mode = mode4x4;
	print_menu(&tmp_game, mode);
	while (1)
	{
		if ((c = getch()) != ERR) {
			if (c == ESC_KEY)
			{
				press_esc(game);
				break ;
			}
			else if (c == KEY_UP || c == KEY_DOWN)
			{
				clear();
				mode = select_mode(mode, c);
				print_menu(&tmp_game, mode);
			}
			else if (c == ENTER_KEY)
			{
				clear();
				break ;
			}
		}
	}
	if (mode == mode4x4)
	{
		game->grid_row_size= 4;
		game->grid_col_size= 4;
	}
	else if (mode == mode4x5)
	{
		game->grid_row_size= 4;
		game->grid_col_size= 5;
	}
	else if (mode == mode5x4)
	{
		game->grid_row_size= 5;
		game->grid_col_size= 4;
	}
	else if (mode == mode5x5)
	{
		game->grid_row_size= 5;
		game->grid_col_size= 5;
	}
	game->mode = mode;
}

