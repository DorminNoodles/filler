/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 21:04:55 by lchety            #+#    #+#             */
/*   Updated: 2017/04/13 18:33:49 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void debug_show_3(t_fil *dna)
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
			dprintf(2, "%c", dna->area[x][y].sign);
			// dprintf(2, "%6d", dna->area[x][y].score);
			x++;
		}
		dprintf(2, "\n");
		y++;
		// ft_putchar_fd('\n', 2);
	}
}

void	play(t_fil *dna)
{


	dprintf(2, "ENTER PLAY\n");
	//diagonale(dna);

	// if (tab[0])
	corner(dna);

	// dprintf(2, "TAB TAB TAB => %d\n", tab[0]);

	debug_score_map(dna);
	check_move(dna);

}



//
// static void debug_show_score(t_fil *dna)
// {
// 	int x;
// 	int y;
//
// 	y = 0;
// 	x = 0;
//
// 	dprintf(dna->debug_fd, "TEST DPRINtF\n");
// 	if (dna->map_score[0][0] == '\0')
// 		dprintf(dna->debug_fd, "KILO OCTET\n");
// 	ft_putstr_fd("DEBUG_SHOW_SCORE !\n", dna->debug_fd);
//
// 	while (y < dna->map.h)
// 	{
// 		x = 0;
// 		while (x < dna->map.w)
// 		{
// 			ft_putstr_fd(ft_itoa(dna->map_score[x][y]), dna->debug_fd);
// 			x++;
// 		}
// 		y++;
// 		ft_putchar_fd('\n', dna->debug_fd);
// 	}
// }
//
// void	play(t_fil *dna)
// {
// 	ft_putstr_fd("PLAY FUNCTION !\n", dna->debug_fd);
// 	dna->map_score = create_score_map(dna);
// 	debug_show_score(dna);
//
// }
