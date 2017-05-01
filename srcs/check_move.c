/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 19:58:40 by lchety            #+#    #+#             */
/*   Updated: 2017/05/01 13:23:50 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_length(t_fil *dna, int x, int y)
{
	int lengthx;
	int lengthy;

	lengthx = x - dna->startx;
	lengthy = y - dna->starty;

	if (lengthx < 0)
		lengthx *= -1;
	if (lengthy < 0)
		lengthy *= -1;

	if (lengthx > lengthy)
		return (lengthx);
	else
		return (lengthy);
}

int		get_indice(t_fil *dna, int length, int div)
{

	if (length < 0)
		length *= -1;
	if (div < 0)
	 div *= -1;
	return (length / div);

}

int		check_liberty(t_fil *dna, int endx, int endy)
{
	int i;
	int	max_length;
	float	deltax;
	float	deltay;
	float	x;
	float	y;

	i = 0;
	x = dna->startx;
	y = dna->starty;

	max_length = get_length(dna, endx, endy);

	deltax = (endx - dna->startx) / (float)max_length;
	deltay = (endy - dna->starty) / (float)max_length;

	// dprintf(2, "deltay => %f\n", deltay);
	// dprintf(2, "max_length => %d\n", max_length);
	// dprintf(2, "SEGFAULT SEARCH\n");

	while (i < (int)max_length)
	{
		// dprintf(2, "HERE > x %f   y %f\n", x, y);
		if (dna->map.area[(int)x][(int)y].sign == dna->enemy_char)
			return (0);
		y += deltay;
		x += deltax;
		i++;
	}
	// dprintf(2, "SEGFAULT SEARCH\n");

	return (1);
}

int		test_each_block(t_fil *dna, int tabx, int taby)
{
	int x;
	int y;
	int weld;
	int score;

	weld = 0;
	y = 0;
	score = 0;
	while (y < dna->piece.h)
	{
		x = 0;
		while (x < dna->piece.w)
		{
			if (dna->piece.tab[x][y] == '*')
			{
				if (tabx + x < 0 || tabx + x >= dna->map.w)
					return (0);
				if (taby + y < 0 || taby + y >= dna->map.h)
					return (0);
				if (dna->map.area[tabx + x][taby + y].sign == dna->enemy_char)
					return (0);
				if (dna->map.area[tabx + x][taby + y].sign == dna->player_char)
					weld++;
				score += dna->map.area[tabx + x][taby + y].score;
			}
			x++;
		}
		y++;
	}

	if (weld == 1)
		return ((score) ? score : 1);
	else
		return (0);
}

void	check_move(t_fil *dna)
{
	int x;
	int y;
	int test;
	int score;

	test = 0;

	dna->move.score = 0;
	dna->move.x = 0;
	dna->move.y = 0;

	y = 0 - dna->piece.h;
	while (y < dna->map.h - 1 && !test)
	{
		x = 0 - dna->piece.w;

		while (x < dna->map.w - 1 && !test)
		{
			if ((score = test_each_block(dna, x, y)))
			{
				if (score > dna->move.score)
				{
					dna->move.score = score;
					dna->move.x = x;
					dna->move.y = y;
				}
			}
			x++;
		}
		y++;
	}
}
