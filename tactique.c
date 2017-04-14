/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tactique.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 12:34:47 by lchety            #+#    #+#             */
/*   Updated: 2017/04/14 22:19:44 by lchety           ###   ########.fr       */
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
		if (x + size <= dna->map.w && y + i < dna->map.h && y + i >= 0)
		{
			if (dna->area[x + size - 1][y + i].score < score)
				dna->area[x + size - 1][y + i].score = score;
		}
		i++;
	}

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

	// dprintf(2, "WAVE !!!!! \n");


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
	int tab[3] = {0, 0, 0};

	// if (dna->area[dna->map.w -2][2].sign == '.')
		//wave(dna, dna->map.w - 1, 0, 100);
	//
	//if (dna->area[(dna->map.w / 2) + 5][dna->map.h - 1].sign == '.')

	//check_liberty(dna);

	dprintf(2, "KAMELOTT => %c\n", dna->area[0][dna->map.h].sign);
	dprintf(2, "KAMELOTT => %d\n", dna->map.h);

	tab[0] = check_liberty(dna, (dna->map.w / 2) + 5, 0);
	tab[1] = check_liberty(dna, (dna->map.w / 2) + 5, dna->map.h - 1);
	tab[2] = check_liberty(dna, 10, dna->map.h -1);

	if (tab[0] && dna->area[(dna->map.w / 2) + 5][0].sign == '.')
	{
		dprintf(2, "UP OK ! ##############################################\n");
		wave(dna, (dna->map.w / 2) + 5, 0, 120);
	}
	else if (tab[1] && dna->area[dna->map.w / 2][dna->map.h / 2].sign == '.')
	{
		dprintf(2, "MIDDLE OK ! ############################################\n");
		wave(dna, dna->map.w / 2, dna->map.h / 2, 120);
	}
	else if (tab[1] && dna->area[(dna->map.w / 2) + 5][dna->map.h - 10].sign == '.')
	{
		dprintf(2, "LIGHT BOTTOM OK ! ##############################################\n");
		wave(dna, (dna->map.w / 2) + 5, dna->map.h - 10, 120);
	}
	else if (tab[1] && dna->area[(dna->map.w / 2) + 5][dna->map.h - 1].sign == '.')
	{
		dprintf(2, "BOTTOM OK ! ##############################################\n");
		wave(dna, (dna->map.w / 2) + 5, dna->map.h - 1, 120);
	}
	else if (tab[2] && dna->area[6][dna->map.h - 1].sign == '.')
	{
		dprintf(2, "LEFT MIDDLE OK ! ##############################################\n");
		wave(dna, 6, dna->map.h - 1, 120);
	}
	else if (tab[2] && dna->area[0][dna->map.h / 2].sign == '.')
	{
		dprintf(2, "LEFT LIGHT BOTTOM OK ! ##############################################\n");
		wave(dna, 0, dna->map.h / 2, 120);
	}
	else if (dna->area[(dna->map.w / 2)][dna->map.h / 2].sign == '.')
	{
		dprintf(2, "BOTTOM RIGHT OK ! ##############################################\n");
		wave(dna, (dna->map.w / 2), dna->map.h / 2, 120);
	}

	// if (dna->area[dna->map.w - 2][dna->map.h - 1].sign == '.' &&
	// dna->area[dna->map.w - 1][dna->map.h - 3].sign == '.' )
	// wave(dna, dna->map.w - 1, dna->map.h - 2, 200);
}

/*
En fait je devrais faire un algo qui regarde si poser la piece dans une direction
nous fait gagner une plus grande distance que si on essaye vers une autre direction

En gros on a deux direction et on pose la piece au benefice de celle ou on gagnera
le plus de terrain

*/
