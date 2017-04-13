/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:20:23 by lchety            #+#    #+#             */
/*   Updated: 2017/04/12 22:13:11 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_game(t_fil *dna, char **line)
{
	dprintf(2, "000000 MARIO 000000\n");
	init_dna(dna);
	get_players(dna, line);
	get_map_size(dna, line);
	create_area(dna, line);
	debug_show_area(dna);
	//init_area(dna, line);

}

void	init_dna(t_fil *dna)
{
	dna->player = 0;
	dna->area = NULL;
	dna->move.x = 0;
	dna->move.y = 0;
	dna->move.score = 0;
	dna->startx = 0;
	dna->starty = 0;

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
