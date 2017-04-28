/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 21:04:55 by lchety            #+#    #+#             */
/*   Updated: 2017/04/28 14:48:46 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	near(t_fil *dna)
{
	int x;
	int y;

	x = 0;
	y = 0;

	while (y < dna->map.h)
	{
		x = 0;
		while (x < dna->map.w)
		{
			if (dna->map.area[x][y].sign == dna->enemy_char)
			{
				if (y - 1 >= 0)
					dna->map.area[x][y - 1].score = NEAR_SCORE;
				if (y + 1 < dna->map.h)
					dna->map.area[x][y + 1].score = NEAR_SCORE;
				if (x - 1 >= 0)
					dna->map.area[x - 1][y].score = NEAR_SCORE;
				if (x + 1 < dna->map.w)
					dna->map.area[x + 1][y].score = NEAR_SCORE;
			}
			x++;
		}
		y++;
	}

}

void	play(t_fil *dna)
{
	near(dna);
	check_move(dna);
}
