/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 19:58:40 by lchety            #+#    #+#             */
/*   Updated: 2017/04/10 00:20:36 by lchety           ###   ########.fr       */
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

	// dprintf(2, "ENTER_TEST_EACH_BLOCK\n");
	weld = 0;
	y = 0;

	// if (tabx == 20 && taby == 23)

	while (y < dna->piece.h)
	{
		x = 0;
		while (x < dna->piece.w)
		{
			if (dna->piece.tab[x][y] == '*')
			{
				// dprintf(2, "=======================> #1\n");
				// if (tabx == 20 && taby == 23)
				// 	dprintf(2, "########################HERE 1\n");

				if (tabx + x < 0 || tabx + x >= dna->map.w)
				{
					// if (tabx == 20 && taby == 23)
					// 	dprintf(2, "########################HERE 2\n");
					return (0);
				}
				if (taby + y < 0 || taby + y >= dna->map.h)
				{
					// if (tabx == 20 && taby == 23)
					// 	dprintf(2, "########################HERE 2\n");
					return (0);
				}
				// dprintf(2, "x=> %d   y=> %d\n", tabx + x, taby +y);
				if (dna->area[tabx + x][taby + y].sign == dna->enemy_char)
					return (0);
				// dprintf(2, "=======================> #2\n");
				// dprintf(2, "%c", dna->area[tabx + x][taby + y].sign);
				if (dna->area[tabx + x][taby + y].sign == dna->player_char)
					weld++;
			}
			x++;
		}
		y++;
	}

	if (weld == 1)
	{
		return (1);
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

	test = 0;

	y = 0 - dna->piece.h;

	while (y < dna->map.h - 1 && !test)
	{
		x = 0 - dna->piece.w;

		while (x < dna->map.w -1 && !test)
		{
			if(test_each_block(dna, x, y))
			{
				dprintf(2, "Good Pos\n");
				dprintf(2, "%d %d\n", y, x);
				dprintf(1, "%d %d\n", y, x);
				test = 1;
			}
			x++;
		}
		// dprintf(2, "Couilles\n");
		y++;
	}
	if (!test)
	{
		dprintf(2, "0 0\n");
		dprintf(1, "0 0\n");
	}

	dprintf(2, "while y => %d\n", y);
	dprintf(2, "END CHECK_MOVE\n");



}
