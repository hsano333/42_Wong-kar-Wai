/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:05:06 by hsano             #+#    #+#             */
/*   Updated: 2022/09/30 14:47:15 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game2048.h"

void set_timeout(int time) {
	time = 1;
	timeout(1);
}

void	init(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
    srand(time(0));
	set_timeout(1);
	timeout(1);
	start_color();
	getmaxyx(game->win, height, width);
	printf("height=%d, width=%d\n", height, width);
}
