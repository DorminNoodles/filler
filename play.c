/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 21:04:55 by lchety            #+#    #+#             */
/*   Updated: 2017/04/26 18:48:31 by lchety           ###   ########.fr       */
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

int		atk_path(t_fil *dna)
{
	if (dna->path.start.x < dna->map.w / 2 &&
	dna->path.start.y < dna->map.h / 2)
		dna->path.aim = vect(dna->map.w - 1, dna->map.h - 1);
	else
		dna->path.aim = vect(0, 0);
	if (pathfinding(dna, dna->path.start, dna->path.aim))
		return (1);
	return (0);
}

int		set_state(t_fil *dna)
{
	if (atk_path(dna))
		return (1);

	return (0);
}

void	meridian(t_fil *dna)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < dna->map.w)
	{
		dna->area[x][dna->map.h/2].score = 3;
		x++;
	}

	while (y < dna->map.h)
	{
		dna->area[dna->map.w / 2][y].score = 3;
		y++;
	}
	y = 0;

	while (y < dna->map.h)
	{
		dna->area[dna->startx][y].score = 3;
		y++;
	}

	x = 0;
	while (x < dna->map.w)
	{
		dna->area[x][dna->starty].score = 3;
		x++;
	}

}

void	near(t_fil *dna)
{
	int x;
	int y;

	x = 0;
	y = 0;

	while (y < dna->map.h)
	{
		x = 0;
		while (x < dna->map.w)
		{
			if (dna->area[x][y].sign == dna->enemy_char)
			{
				if (y - 1 >= 0)
					dna->area[x][y - 1].score = NEAR_SCORE;
				if (y + 1 < dna->map.h)
					dna->area[x][y + 1].score = NEAR_SCORE;
				if (x - 1 >= 0)
					dna->area[x - 1][y].score = NEAR_SCORE;
				if (x + 1 < dna->map.w)
					dna->area[x + 1][y].score = NEAR_SCORE;
			}
			x++;
		}
		y++;
	}

}

void	play(t_fil *dna)
{
	int state;

	state = 0;

	//dprintf(2, "ENTER PLAY\n");
	//pathfinding(dna, vect(dna->path.start.x, dna->path.start.y),
	//vect(dna->path.aim.x, dna->path.aim.y));
	//state = set_state(dna);
	//diagonale(dna);
	// if (tab[0])
	// dprintf(2, "TAB TAB TAB => %d\n", tab[0]);

	//meridian(dna);
	near(dna);
	check_move(dna);
	// debug_score_map(dna);

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
