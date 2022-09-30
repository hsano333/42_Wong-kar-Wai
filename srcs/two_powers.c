/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_powers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 20:24:25 by hsano             #+#    #+#             */
/*   Updated: 2022/10/01 01:41:21 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game2048.h"
#include "numbers.h"

void	get_aa_str2(int row, char *line)
{
	attron(COLOR_PAIR(2));
	get_aa_two(row, line);
}

void	get_aa_str4(int row, char *line)
{
	attron(COLOR_PAIR(3));
	get_aa_four(row, line);
}

void	get_aa_str8(int row, char *line)
{
	attron(COLOR_PAIR(4));
	get_aa_eight(row, line);
}

void	get_aa_str16(int row, char *line)
{
	attron(COLOR_PAIR(5));
	get_aa_one(row, line);
	get_aa_six(row, &(line[AA_SIZE]));
}

void	get_aa_str32(int row, char *line)
{
	attron(COLOR_PAIR(6));
	get_aa_three(row, line);
	get_aa_two(row, &(line[AA_SIZE]));
}

void	get_aa_str64(int row, char *line)
{
	attron(COLOR_PAIR(7));
	get_aa_six(row, line);
	get_aa_four(row, &(line[AA_SIZE]));
}

void	get_aa_str128(int row, char *line)
{
	attron(COLOR_PAIR(8));
	get_aa_one(row, line);
	get_aa_two(row, &(line[AA_SIZE]));
	get_aa_eight(row, &(line[AA_SIZE * 2]));
}

void	get_aa_str256(int row, char *line)
{
	attron(COLOR_PAIR(9));
	get_aa_two(row, line);
	get_aa_five(row, &(line[AA_SIZE]));
	get_aa_six(row, &(line[AA_SIZE * 2]));
}

void	get_aa_str512(int row, char *line)
{
	attron(COLOR_PAIR(10));
	get_aa_five(row, line);
	get_aa_one(row, &(line[AA_SIZE]));
	get_aa_two(row, &(line[AA_SIZE * 2]));
}

void	get_aa_str1024(int row, char *line)
{
	attron(COLOR_PAIR(11));
	get_aa_one(row, line);
	get_aa_zero(row, &(line[AA_SIZE]));
	get_aa_two(row, &(line[AA_SIZE * 2]));
	get_aa_four(row, &(line[AA_SIZE * 3]));
}

void	get_aa_str2048(int row, char *line)
{
	attron(COLOR_PAIR(12));
	get_aa_two(row, line);
	get_aa_zero(row, &(line[AA_SIZE]));
	get_aa_four(row, &(line[AA_SIZE * 2]));
	get_aa_eight(row, &(line[AA_SIZE * 3]));
}

void	get_aa_str4096(int row, char *line)
{
	get_aa_four(row, line);
	get_aa_zero(row, &(line[AA_SIZE]));
	get_aa_nine(row, &(line[AA_SIZE * 2]));
	get_aa_six(row, &(line[AA_SIZE * 3]));
}

void	get_aa_str8192(int row, char *line)
{
	get_aa_eight(row, line);
	get_aa_one(row, &(line[AA_SIZE]));
	get_aa_nine(row, &(line[AA_SIZE * 2]));
	get_aa_two(row, &(line[AA_SIZE * 3]));
}

void	get_aa_str16384(int row, char *line)
{
	get_aa_one(row, line);
	get_aa_six(row, &(line[AA_SIZE]));
	get_aa_three(row, &(line[AA_SIZE * 2]));
	get_aa_eight(row, &(line[AA_SIZE * 3]));
	get_aa_four(row, &(line[AA_SIZE * 4]));
}

void	get_aa_str32768(int row, char *line)
{
	get_aa_three(row, line);
	get_aa_two(row, &(line[AA_SIZE]));
	get_aa_seven(row, &(line[AA_SIZE * 2]));
	get_aa_six(row, &(line[AA_SIZE * 3]));
	get_aa_eight(row, &(line[AA_SIZE * 4]));
}

void	get_aa_str65536(int row, char *line)
{
	get_aa_six(row, line);
	get_aa_five(row, &(line[AA_SIZE]));
	get_aa_five(row, &(line[AA_SIZE * 2]));
	get_aa_three(row, &(line[AA_SIZE * 3]));
	get_aa_six(row, &(line[AA_SIZE * 4]));
}
