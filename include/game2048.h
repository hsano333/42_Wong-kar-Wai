/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2048.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:05:48 by hsano             #+#    #+#             */
/*   Updated: 2022/10/01 15:32:51 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GAME2048_H
# define GAME2048_H
# include <ncurses.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <sys/time.h>
# include <locale.h>

#define AA_SIZE 8
#define ESC_KEY 27
#define ENTER_KEY 10

typedef struct s_game
{
	int		win_value;
	int		win_flag;
	int		grid_row_size;
	int		grid_col_size;
	int		board[5][5];
	int		score;
	int		max_score;
	int		end_flag;
	WINDOW	*win;	

}	t_game;

enum e_const
{
	WIN_VALUE = 2048
};

enum e_number
{
	V1 = 1, 
	V2 = 2, 
	V4 = 4, 
	V8 = 8, 
	V16 = 16, 
	V32 = 32, 
	V64 = 64, 
	V128 = 128, 
	V256 = 256, 
	V512 = 512,
	V1024 = 1024,
	V2048 = 2048,
	V4096 = 4096,
	V8192 = 8192,
	V16384 = 16384,
	V32768 = 32768,
	V65536 = 65536,
	V2048MENU = 1000000,
};

int		init(t_game *game);
void	menu(t_game *game);
void	update_board(t_game *game);
void	play(t_game *game);
void	send_key_board(int key, t_game *game);
void	print_one_frame_line(t_game *game, int row, int frame_row, int is_pipe);
void	clear_board(t_game *game);
#endif
