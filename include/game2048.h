/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2048.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiyu <smiyu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:05:48 by hsano             #+#    #+#             */
/*   Updated: 2022/10/01 19:23:52 by smiyu            ###   ########.fr       */
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
//#define UP_KEY

typedef struct s_game
{
	int		win_value;
	int		grid_row_size;
	int		grid_col_size;
	int		board[5][5];
	int		score;
	WINDOW	*win;	

}	t_game;

enum e_const
{
	WIN_VALUE = 2048
};

enum e_number
{
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
};

int		init(t_game *game);
void	menu(t_game *game);
void	update_board(t_game *game);
void	play(t_game *game);
void	send_key_board(int key, t_game *game);
int		check_board(t_game *game);
#endif
