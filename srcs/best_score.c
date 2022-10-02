#include "game2048.h"
#include "libft.h"
#include "stdlib.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"

#define SCORE_FILE "best_score"

#define MODE_STR1 "4x4:"
#define MODE_STR2 "4x5:"
#define MODE_STR3 "5x4:"
#define MODE_STR4 "5x5:"

#include "unistd.h"
int parse_score(char *buf, game_mode mode, char *num)
{
	int	i;
	int	j;
	int	colon_num;
	int	best_score;
	int	err;

	i = 0;
	j = 0;
	colon_num = 0;
	while (colon_num < (int)mode && buf[i])
	{
		if (buf[i] == ':')
			colon_num++;
		i++;
	}
	while (j < 16 && buf[i])
	{
		num[j] = buf[i];
		if (buf[i] == '\n')
			break ;
		i++;
		j++;
	}
	num[j] = '\0';
	err = false;
	best_score = ft_atoi(num, &err);
	if (err)
		return (0);
	refresh();
	return (best_score);
}

int	get_best_score(game_mode mode)
{
	int		fd;
	int		read_num;
	char	buf[128];
	char	num[32];
	int		best_score;

	best_score = 0;
	fd = open(SCORE_FILE, O_RDONLY);
	if (fd < 0)
		return (0);
	else
	{
		read_num = read(fd, buf, 128);
		if (read_num < 0 || read_num > 64)
			return (0);
		buf[read_num - 1] = '\0';
		best_score = parse_score(buf, mode, num);
	}
	close(fd);
	return (best_score);
}

void	write_best_score(t_game *game, int fd, game_mode mode)
{
	char	str_num[128];
	char	buf[128];
	size_t	len;
	int		i;

	i = 0;
	while (i < 128)
		str_num[i++] = 0;
	i = 0;
	while (i < 128)
		buf[i++] = 0;
	if (mode == mode4x4)
		write(fd, MODE_STR1, 4);
	else if (mode == mode4x5)
		write(fd, MODE_STR2, 4);
	else if (mode == mode5x4)
		write(fd, MODE_STR3, 4);
	else if (mode == mode5x5)
		write(fd, MODE_STR4, 4);
	ft_itoa_no_memory(game->best_score[mode], buf, str_num);
	len = ft_strlen(str_num);
	str_num[len] = '\n';
	str_num[len + 1] = '\0';
	write(fd, str_num, len + 1);
}

void	set_best_score(t_game *game, int score)
{
	int		fd;
	int		option;

	game->best_score[game->mode] = score;
	option = O_WRONLY | O_CREAT;
	fd = open(SCORE_FILE, option, 0644);
	if (fd < 0)
		return ;
	write_best_score(game, fd, mode4x4);
	write_best_score(game, fd, mode4x5);
	write_best_score(game, fd, mode5x4);
	write_best_score(game, fd, mode5x5);
	close(fd);
}
