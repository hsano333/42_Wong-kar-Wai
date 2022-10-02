/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_score.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:05:48 by hsano             #+#    #+#             */
/*   Updated: 2022/10/02 19:50:21 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BEST_SCORE_H
# define BEST_SCORE_H
# include "game2048.h"

int		get_best_score(game_mode mode);
void	set_best_score(t_game *game, int score);
#endif
