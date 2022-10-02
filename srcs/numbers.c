/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/0AA_SIZE + 1/30 16:36:05 by hsano             #+#    #+#   */
/*   Updated: 2022/10/02 17:15:09 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game2048.h"

void	get_aa_zero(int row, char *line)
{
	char zero[AA_SIZE][AA_SIZE + 1] = {
	"  ###   ",
	" ##  #  ",
	" #   ## ",
	" #    # ",
	" #    # ",
	" #   ## ",
	" ##  #  ",
	"  ###   ",
	};
	int	i;	

	i = 0;
	while (i < AA_SIZE)
	{
		line[i] = zero[row][i];
		i++;
	}
};

void	get_aa_one(int row, char *line)
{
	char one[AA_SIZE][AA_SIZE + 1] = {
		"    ##  ",
		"  ####  ",
		"    ##  ",
		"    ##  ",
		"    ##  ",
		"    ##  ",
		"    ##  ",
		"    ##  ",
	};
	int	i;	

	i = 0;
	while (i < AA_SIZE)
	{
		line[i] = one[row][i];
		i++;
	}
};

void	get_aa_two(int row, char *line)
{
	char	 two[AA_SIZE][AA_SIZE + 1] = {
		"  ####  ",
		" ##  ## ",
		" #   ## ",
		"     ## ",
		"    ##  ",
		"   ##   ",
		"  #     ",
		" ###### ",
	};
	int	i;	

	i = 0;
	while (i < AA_SIZE)
	{
		line[i] = two[row][i];
		i++;
	}
};

void	get_aa_three(int row, char *line)
{
	char three[AA_SIZE][AA_SIZE + 1] = {
	"  ###   ",
	" #   #  ",
	"    ##  ",
	"   ##   ",
	"     #  ",
	"     ## ",
	" #   #  ",
	"  ####  ",
	};
	int	i;	

	i = 0;
	while (i < AA_SIZE)
	{
		line[i] = three[row][i];
		i++;
	}
};

void	get_aa_four(int row, char *line)
{
	char four[AA_SIZE][AA_SIZE + 1] = {
	"     #  ",
	"    ##  ",
	"   # #  ",
	"  #  #  ",
	" #   #  ",
	"####### ",
	"     #  ",
	"     #  ",
	};
	int	i;	

	i = 0;
	while (i < AA_SIZE)
	{
		line[i] = four[row][i];
		i++;
	}
};

void	get_aa_five(int row, char *line)
{
	char five[AA_SIZE][AA_SIZE + 1] = {
	"  ####  ",
	" ##     ",
	" #      ",
	" #####  ",
	" #   ## ",
	"      # ",
	"     #  ",
	"  ####  ",
};
	int	i;	

	i = 0;
	while (i < AA_SIZE)
	{
		line[i] = five[row][i];
		i++;
	}
};

void	get_aa_six(int row, char *line)
{
	char six[AA_SIZE][AA_SIZE + 1] = {
	"   ###  ",
	"  #     ",
	" #      ",
	" # ###  ",
	" ##  ## ",
	" #    # ",
	" ##  ## ",
	"  ####  ",
	};
	int	i;	

	i = 0;
	while (i < AA_SIZE)
	{
		line[i] = six[row][i];
		i++;
	}
};

void	get_aa_seven(int row, char *line)
{
	char seven[AA_SIZE][AA_SIZE + 1] = {
	" ###### ",
	"     #  ",
	"     #  ",
	"    #   ",
	"   #    ",
	"   #    ",
	"   #    ",
	"  ##    ",
	};
	int	i;	

	i = 0;
	while (i < AA_SIZE)
	{
		line[i] = seven[row][i];
		i++;
	}
};

void	get_aa_eight(int row, char *line)
{
	char eight[AA_SIZE][AA_SIZE + 1] = {
	"  ####  ",
	" #    # ",
	" #   #  ",
	"  ###   ",
	" ##  ## ",
	" #    # ",
	" #   ## ",
	"  ####  ",
	};
	int	i;	

	i = 0;
	while (i < AA_SIZE)
	{
		line[i] = eight[row][i];
		i++;
	}
};

void	get_aa_nine(int row, char *line)
{
	char	nine[AA_SIZE][AA_SIZE + 1] = {
	"  ####  ",
	" #    # ",
	" #    # ",
	"  ##### ",
	"      # ",
	" #   ## ",
	" #####  ",
	"        ",
	};
	int	i;	

	i = 0;
	while (i < AA_SIZE)
	{
		line[i] = nine[row][i];
		i++;
	}
};
