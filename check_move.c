/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 19:58:40 by lchety            #+#    #+#             */
/*   Updated: 2017/04/13 18:31:36 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void 	debug_show_piece(t_fil *dna)
{
	int x;
	int y;

	y = 0;
	while (y < dna->piece.h)
	{
		x = 0;
		while (x < dna->piece.w)
		{
			dprintf(2, "%c", dna->piece.tab[x][y]);
			x++;
		}
		dprintf(2, "\n");
		y++;
	}
}

void	check_sign()
{

}

void	draw_ray(t_fil *dna, void (*fptr)())
{




}

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

	 dprintf(2, "get_indice length => %d\n", length);
	 dprintf(2, "get_indice div => %d\n", div);
		//dprintf(2, "length => %d\n", length);
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

	dprintf(2, "deltay => %f\n", deltay);
	dprintf(2, "max_length => %d\n", max_length);
	dprintf(2, "SEGFAULT SEARCH\n");

	while (i < (int)max_length)
	{
		dprintf(2, "HERE > x %f   y %f\n", x, y);
		if (dna->area[(int)x][(int)y].sign == dna->enemy_char)
			return (0);
		y += deltay;
		x += deltax;
		i++;
	}
	dprintf(2, "SEGFAULT SEARCH\n");

	return (1);
}

// int		check_contact(t_fil *dna, int x, int y, int score)
// {
// 	if (y - 1 >= 0 && dna->area[x][y - 1].sign == dna->player_char)
// 		score *= 0.85;
//
// 	if (y + 1 < dna->map.h && dna->area[x][y + 1].sign == dna->player_char)
// 		score *= 0.85;
//
// 	if (x - 1 >= 0 && dna->area[x - 1][y].sign == dna->player_char)
// 		score *= 0.85;
//
// 	if (x + 1 < dna->map.w && dna->area[x + 1][y].sign == dna->player_char)
// 		score *= 0.85;
//
// 	return (score);
// }

int		check_contact(t_fil *dna, int x, int y, int score)
{
	if (y - 1 >= 0 && dna->area[x][y - 1].sign != dna->player_char)
		score += 0;

	if (y + 1 < dna->map.h && dna->area[x][y + 1].sign != dna->player_char)
		score += 0;

	if (x - 1 >= 0 && dna->area[x - 1][y].sign != dna->player_char)
		score += 0;

	if (x + 1 < dna->map.w && dna->area[x + 1][y].sign != dna->player_char)
		score += 0;

	return (score);
}

int		test_each_block(t_fil *dna, int tabx, int taby)
{
	int x;
	int y;
	int weld;
	int score;

	// dprintf(2, "ENTER_TEST_EACH_BLOCK\n");
	weld = 0;
	y = 0;
	score = 0;

	// if (tabx == 20 && taby == 23)

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
				if (dna->area[tabx + x][taby + y].sign == dna->enemy_char)
					return (0);
				if (dna->area[tabx + x][taby + y].sign == dna->player_char)
					weld++;
				score += dna->area[tabx + x][taby + y].score;
				score = check_contact(dna, tabx + x, tabx + y, score);
			}
			x++;
		}
		y++;
	}


	if (weld == 1)
	{
		// dprintf(2, "Find Move x %d  y %d  \n", tabx, taby);
		// dprintf(2, "Score = > %d  \n", score);
		return ((score) ? score : 1);
	}
	else
	{
		// if (tabx == 20 && taby == 23)
		// 	dprintf(2, "################## WELD COUPABLE = %d\n", weld);
		return (0);
	}
}


void	check_move(t_fil *dna)
{
	debug_show_piece(dna);

	dprintf(2, "ENTER CHECK_MOVE\n");

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

		while (x < dna->map.w -1 && !test)
		{
			if ((score = test_each_block(dna, x, y)))
			{
				if (score > dna->move.score)
				{
					// dprintf(2, "More scoring\n");
					dna->move.score = score;
					dna->move.x = x;
					dna->move.y = y;
				}
			}
			x++;
		}
		// dprintf(2, "Couilles\n");
		y++;
	}
	 dprintf(2, "best => %d %d\n", dna->move.y, dna->move.x);
	 dprintf(1, "%d %d\n", dna->move.y, dna->move.x);
	// if (!test)
	// {
	// 	dprintf(2, "0 0\n");
	// 	dprintf(1, "0 0\n");
	// }

	// dprintf(2, "while y => %d\n", y);
	dprintf(2, "END CHECK_MOVE\n");

}
