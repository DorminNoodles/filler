/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tactique.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 12:34:47 by lchety            #+#    #+#             */
/*   Updated: 2017/04/11 16:05:34 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	make_square(t_fil *dna, int x, int y, int size, int score)
{
	int i;

	i = 0;
	//up
	while (i < size)
	{
		if (x + i >= 0 && x + i < dna->map.w && y >= 0)
		{
			if (dna->area[x + i][y].score < score)
				dna->area[x + i][y].score = score;
		}
		if (x + i >= 0 && x + i < dna->map.w && y + size - 1 < dna->map.h)
		{
			if (dna->area[x + i][y + size - 1].score < score)
				dna->area[x + i][y + size - 1].score = score;
		}
		if (x >= 0 && y + i < dna->map.h && y + i >= 0)
		{
			if (dna->area[x][y + i].score < score)
				dna->area[x][y + i].score = score;
		}
		if (x + size < dna->map.w && y + i < dna->map.h && y + i >= 0)
		{
			if (dna->area[x + size][y + i].score < score)
				dna->area[x + size][y + i].score = score;
		}
		i++;
	}
	i = 0;

}

void	score_multiply(t_fil *dna, int x, int y, int size, int score)
{
	int i;

	i = 0;
	//up
	while (i < size)
	{
		if (x + i >= 0 && x + i < dna->map.w && y >= 0)
		{
			//if (dna->area[x + i][y].score < score)
				dna->area[x + i][y].score *= score;
		}
		if (x + i >= 0 && x + i < dna->map.w && y + size - 1 < dna->map.h)
		{
			// if (dna->area[x + i][y + size - 1].score < score)
				dna->area[x + i][y + size - 1].score *= score;
		}
		if (x >= 0 && y + i < dna->map.h && y + i >= 0)
		{
			// if (dna->area[x][y + i].score < score)
				dna->area[x][y + i].score *= score;
		}
		if (x + size < dna->map.w && y + i < dna->map.h && y + i >= 0)
		{
			// if (dna->area[x + size][y + i].score < score)
				dna->area[x + size][y + i].score *= score;
		}
		i++;
	}
	i = 0;

}

void	wave(t_fil *dna, int x, int y, int score)
{
	int size;
	int i;
	int j;
	int o;
	int tmp;

	i = 1;
	j = 0;
	o = 0;
	size = 50;

	dna->area[x][y].score = score;
	while (i < size)
	{
		// dprintf(2, "1/2 = %d\n", 1/2);
		make_square(dna, x - i, y - i, (i * 2) + 1, score - i);
		i++;
	}
}
//
// void	wave_diag(t_fil *dna, int x, int y, int score)
// {
// 	int size;
// 	int i;
// 	int j;
// 	int o;
//
// 	i = 1;
// 	j = 0;
// 	o = 0;
// 	size = 50;
//
// 	while (i < size)
// 	{
// 		// dprintf(2, "1/2 = %d\n", 1/2);
// 		score_multiply(dna, x - i, y - i, (i * 2) + 1, score);
// 		i++;
// 	}
// }

void	diagonale(t_fil *dna)
{
	int x;
	int y;

	x = 0;
	y = dna->map.h;

	while (y >= 0 && x < dna->map.w)
	{
		//wave_diag(dna, x, y, 2);

		y--;
		x++;
	}


}

void	corner(t_fil *dna)
{
	// if (dna->area[dna->map.w -2][2].sign == '.')
		wave(dna, dna->map.w - 1, 0, 100);

	if (dna->area[dna->map.w / 2][dna->map.h].sign == '.' &&
		dna->area[dna->map.w / 2 + 1][dna->map.h].sign == '.' &&
		dna->area[dna->map.w / 2 - 1][dna->map.h].sign == '.')
		wave(dna, dna->map.w / 2, dna->map.h - 1, 120);

	// if (dna->area[dna->map.w - 2][dna->map.h - 1].sign == '.' &&
	// dna->area[dna->map.w - 1][dna->map.h - 3].sign == '.' )
	// 	wave(dna, dna->map.w - 1, dna->map.h - 2, 200);
}
