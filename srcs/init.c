#include "game2048.h"

void set_timeout(int time) {
	time = 1;
	timeout(1);
	(void)time;
}

static void	init_color_pair(void)
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(8, COLOR_MAGENTA, COLOR_CYAN);
	init_pair(9, COLOR_GREEN, COLOR_MAGENTA);
	init_pair(10, COLOR_BLUE, COLOR_GREEN);
	init_pair(11, COLOR_RED, COLOR_BLUE);
	init_pair(12, COLOR_YELLOW, COLOR_RED);
	init_pair(13, COLOR_RED, COLOR_GREEN);
	init_pair(14, COLOR_RED, COLOR_CYAN);
	//bkgd(3);
	//attrset(2);
	attron(COLOR_PAIR(4));

	if (has_colors())
		printw("color OK\n");
	else
		printw("color NG\n");

}

int	check_win_value(void)
{
	int	number;

	number = WIN_VALUE;
	if (number == V1)
		return (true);
	else if (number == V2)
		return (true);
	else if (number == V4)
		return (true);
	else if (number == V8)
		return (true);
	else if (number == V16)
		return (true);
	else if (number == V32)
		return (true);
	else if (number == V64)
		return (true);
	else if (number == V128)
		return (true);
	else if (number == V256)
		return (true);
	else if (number == V512)
		return (true);
	else if (number == V1024)
		return (true);
	else if (number == V2048)
		return (true);
	return (false);
}

int	init(t_game *game)
{
	game->score = 0;
	game->win_flag = 0;
	game->end_flag = 0;
	if (!check_win_value())
		return (false);
	game->win_value = WIN_VALUE;
	if (game->win_value == V1 || game->win_value == V2)
		game->win_flag = true;
	init_color_pair();
	clear_board(game);
    srand(time(0));
	set_timeout(1);
	timeout(1);
	start_color();
	keypad(game->win, TRUE);
	return (true);
}
