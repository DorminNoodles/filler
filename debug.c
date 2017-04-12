/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 12:20:55 by lchety            #+#    #+#             */
/*   Updated: 2017/04/12 13:17:38 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void debug_score_map(t_fil *dna)
{
	int x;
	int y;

	y = 0;
	x = 0;

	while (y < dna->map.h)
	{
		// dprintf(2, "%d\n", dna->map.h);
		// dprintf(2, "\n @=>");
		x = 0;
		while (x < dna->map.w)
		{
			// dprintf(2, "%c", dna->area[x][y].sign);
			dprintf(2, "%5d", dna->area[x][y].score);
			x++;
		}
		dprintf(2, "\n");
		y++;
		// ft_putchar_fd('\n', 2);
	}
}
