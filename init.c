/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:20:23 by lchety            #+#    #+#             */
/*   Updated: 2017/04/11 15:31:55 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_dna(t_fil *dna)
{
	dna->player = 0;
	dna->area = NULL;
	dna->move.x = 0;
	dna->move.y = 0;
	dna->move.score = 0;

}

void	reset_score(t_fil *dna)
{
	int x;
	int y;

	y = 0;
	x = 0;

	while (y < dna->map.h)
	{
		x = 0;
		while (x < dna->map.w)
		{
			dna->area[x][y].score = 0;
			// dprintf(2, "%3d", dna->area[x][y].score);
			x++;
		}
		// dprintf(2, "\n");
		y++;
	}
}

void	reset(t_fil *dna)
{
	reset_score(dna);
}
