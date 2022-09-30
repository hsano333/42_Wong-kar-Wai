/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:11:35 by hsano             #+#    #+#             */
/*   Updated: 2022/09/30 21:05:30 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game2048.h"
#include "unistd.h"

int main(void)
{
	t_game	game;

    game.win = initscr();
	init(&game);

	menu(&game);
	//printw("%s\n", two[8]);
	printw("update board \n");
	update_board(&game);
	refresh();
	usleep(1000000);

	endwin();
}
