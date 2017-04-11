/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 19:58:40 by lchety            #+#    #+#             */
/*   Updated: 2017/04/11 12:30:13 by lchety           ###   ########.fr       */
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
			}
			x++;
		}
		y++;
	}


	if (weld == 1)
	{
		// dprintf(2, "Find Move x %d  y %d  \n", tabx, taby);
		// dprintf(2, "Score = > %d  \n", score);
		return (score);
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
				dprintf(2, "dna => %d\n", dna->move.score);
				if (score > dna->move.score)
				{
					// dprintf(2, "More scoring\n");
					dna->move.score = score;
					dna->move.x = x;
					dna->move.y = y;
				}
			// 	dprintf(2, "Good Pos\n");
			// 	dprintf(2, "%d %d\n", y, x);
			// 	dprintf(1, "%d %d\n", y, x);
			// 	test = 1;
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
