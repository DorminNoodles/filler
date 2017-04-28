/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 12:20:55 by lchety            #+#    #+#             */
/*   Updated: 2017/04/28 14:27:21 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void debug_show_area(t_fil *dna)
{
	int x;
	int y;

	x = 0;
	y = 0;

	ft_putstr_fd("DEBUG_SHOW_AREA\n", 2);
	while (y < dna->map.h)
	{
		x = 0;
		while (x < dna->map.w)
		{
			dprintf(2, "%4d", dna->area[x][y].score);
			// dprintf(2, "%c", dna->area[x][y].sign);
			x++;
		}
		y++;
		dprintf(2, "\n");
	}
}

void debug_show(t_fil *dna)
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
			dprintf(2, "%3d", dna->area[x][y].score);
			x++;
		}
		dprintf(2, "\n");
		y++;
	}
}

void debug_show_2(t_fil *dna)
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
			dprintf(2, "%c", dna->area[x][y].sign);
			x++;
		}
		dprintf(2, "\n");
		y++;
	}
}

void debug_score_map(t_fil *dna)
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
			dprintf(2, "%2d", dna->area[x][y].score);
			x++;
		}
		dprintf(2, "\n");
		y++;
	}
}

void debug_path_map(t_fil *dna)
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
			dprintf(2, "%2c", dna->area[x][y].path);
			x++;
		}
		dprintf(2, "\n");
		y++;
	}
}
