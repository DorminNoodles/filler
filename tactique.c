/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tactique.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 12:34:47 by lchety            #+#    #+#             */
/*   Updated: 2017/04/17 11:58:39 by lchety           ###   ########.fr       */
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

// void	corner(t_fil *dna)
// {
// 	int tab[3] = {0, 0, 0};
//
// 	// if (dna->area[dna->map.w -2][2].sign == '.')
// 		//wave(dna, dna->map.w - 1, 0, 100);
// 	//
// 	//if (dna->area[(dna->map.w / 2) + 5][dna->map.h - 1].sign == '.')
//
// 	//check_liberty(dna);
//
// 	dprintf(2, "KAMELOTT => %c\n", dna->area[0][dna->map.h].sign);
// 	dprintf(2, "KAMELOTT => %d\n", dna->map.h);
//
// 	tab[0] = check_liberty(dna, (dna->map.w / 2) + 5, 0);
// 	tab[1] = check_liberty(dna, (dna->map.w / 2) + 5, dna->map.h - 1);
// 	tab[2] = check_liberty(dna, 10, dna->map.h -1);
//
// 	if (tab[0] && dna->area[(dna->map.w / 2) + 5][0].sign == '.')
// 	{
// 		dprintf(2, "UP OK ! ##############################################\n");
// 		wave(dna, (dna->map.w / 2) + 5, 0, 120);
// 	}
// 	else if (tab[1] && dna->area[dna->map.w / 2][dna->map.h / 2].sign == '.')
// 	{
// 		dprintf(2, "MIDDLE OK ! ############################################\n");
// 		wave(dna, dna->map.w / 2, dna->map.h / 2, 120);
// 	}
// 	else if (tab[1] && dna->area[(dna->map.w / 2) + 5][dna->map.h - 10].sign == '.')
// 	{
// 		dprintf(2, "LIGHT BOTTOM OK ! ##############################################\n");
// 		wave(dna, (dna->map.w / 2) + 5, dna->map.h - 10, 120);
// 	}
// 	else if (tab[1] && dna->area[(dna->map.w / 2) + 5][dna->map.h - 1].sign == '.')
// 	{
// 		dprintf(2, "BOTTOM OK ! ##############################################\n");
// 		wave(dna, (dna->map.w / 2) + 5, dna->map.h - 1, 120);
// 	}
// 	else if (tab[2] && dna->area[6][dna->map.h - 1].sign == '.')
// 	{
// 		dprintf(2, "LEFT MIDDLE OK ! ##############################################\n");
// 		wave(dna, 6, dna->map.h - 1, 120);
// 	}
// 	else if (tab[2] && dna->area[0][dna->map.h / 2].sign == '.')
// 	{
// 		dprintf(2, "LEFT LIGHT BOTTOM OK ! ##############################################\n");
// 		wave(dna, 0, dna->map.h / 2, 120);
// 	}
// 	else if (dna->area[(dna->map.w / 2)][dna->map.h / 2].sign == '.')
// 	{
// 		dprintf(2, "BOTTOM RIGHT OK ! ##############################################\n");
// 		wave(dna, (dna->map.w / 2), dna->map.h / 2, 120);
// 	}
// }


int		upper(t_fil *dna, char c)
{
	int x;
	int y;

	x = 0;
	y = 0;

	while (y < dna->map.h)
	{
		// dprintf(2, "#%d#\n", y);
		x = 0;
		while (x < dna->map.w)
		{
			if (dna->area[x][y].sign == c)
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int		lower(t_fil *dna, char c)
{
	int x;
	int y;

	x = 0;
	y = dna->map.h - 1;

	while (y >= 0)
	{
		x = 0;
		while (x < dna->map.w)
		{
			if (dna->area[x][y].sign == c)
				return (y);
			x++;
		}
		y--;
	}
	return (0);
}

int		right(t_fil *dna, char c)
{
	int x;
	int y;

	x = dna->map.w - 1;
	y = 0;

	while (x >= 0)
	{
		y = 0;
		while (y < dna->map.h)
		{
			if (dna->area[x][y].sign == c)
				return (x);
			y++;
		}
		x--;
	}
	return (0);
}

void	find_bounds(t_fil *dna, int bounds[], char c)
{
	bounds[0] = upper(dna, c);
	bounds[1] = lower(dna, c);
	bounds[2] = right(dna, c);
}


void	corner(t_fil *dna)
{
	int tab[6] = {0, 0, 0};
	int bounds_enemy[6] = {0, 0, 0, 0, 0, 0};
	int bounds_player[6] = {0, 0, 0, 0, 0, 0};
	//int test[];
	find_bounds(dna, bounds_enemy, dna->enemy_char);

	dprintf(2, "######################TEST_BOUNDS => %d\n", bounds_enemy[2]);
	find_bounds(dna, bounds_player, dna->player_char);
	// if (dna->area[dna->map.w -2][2].sign == '.')
		//wave(dna, dna->map.w - 1, 0, 100);
	//
	//if (dna->area[(dna->map.w / 2) + 5][dna->map.h - 1].sign == '.')

	//check_liberty(dna);

	//dprintf(2, "KAMELOTT => %c\n", dna->area[0][dna->map.h].sign);
	//dprintf(2, "KAMELOTT => %d\n", dna->map.h);

	tab[0] = check_liberty(dna, dna->map.w / 2, dna->map.h / 2 + 5);
	tab[1] = check_liberty(dna, dna->map.w / 2 - 5, dna->map.h / 2 + 5);
	tab[2] = check_liberty(dna, 0, dna->map.h / 2);
	tab[3] = check_liberty(dna, dna->map.w / 2, dna->map.h - 1);
	tab[4] = check_liberty(dna, dna->map.w / 2, 0);
	tab[5] = check_liberty(dna, 0, dna->map.h);
	//tab[2] = check_liberty(dna, 10, dna->map.h -1);

	// if (tab[1] && dna->area[dna->map.w / 2 + 4][dna->map.h / 2 + 4].sign == '.')
	// {
	// 	dprintf(2, "CLOSE MIDDLE OK ! ############################################\n");
	// 	wave(dna, dna->map.w / 2 + 4, dna->map.h / 2 + 4, 120);
	// }

	dprintf(2, "bounds_enemy => %d\n", bounds_enemy[1]);
	dprintf(2, "bounds_player => %d\n", bounds_player[1]);


	dprintf(2, "tab4 => %d\n", tab[4]);
	dprintf(2, "tab4 => %d\n", tab[4]);
	if (tab[4] && dna->area[dna->map.w / 2 - 4][0].sign == '.' && bounds_enemy[0] < bounds_player[0] && bounds_enemy[2] > dna->map.w / 2 - 4)
	{
		dprintf(2, "UP OK ! ############################################\n");
		wave(dna, dna->map.w / 2, 0, 120);
	}
	else if (dna->area[dna->map.w / 2][dna->map.h - 1].sign == '.' && bounds_enemy[1] > bounds_player[1])
	{
		dprintf(2, "DOWN OK ! ############################################\n");
		wave(dna, dna->map.w / 2, dna->map.h - 1, 120);
	}
	else if (tab[0] && dna->area[dna->map.w / 2][dna->map.h / 2 + 5].sign == '.')
	{
		dprintf(2, "GO MIDDLE ! ############################################\n");
		wave(dna, dna->map.w / 2, dna->map.h / 2 + 5, 120);
	}
	// else if (tab[0] && dna->area[dna->map.w / 2 - 5][dna->map.h / 2 + 5].sign == '.')
	// {
	// 	dprintf(2, "GO MORE MIDDLE ! ############################################\n");
	// 	wave(dna, dna->map.w / 2, dna->map.h / 2 - 5, 120);
	// }
	else if (tab[3] && dna->area[dna->map.w / 2][dna->map.h - 1].sign == '.')
	{
		dprintf(2, "GO MORE MIDDLE ! ############################################\n");
		wave(dna, dna->map.w / 2, dna->map.h - 1, 120);
	}
	else if (tab[2] && dna->area[0][dna->map.h / 2].sign == '.')
	{
		dprintf(2, "GO MORE MIDDLE ! ############################################\n");
		wave(dna, 0, dna->map.h / 2, 120);
	}
	else if (tab[5] && dna->area[0][dna->map.h - 1].sign == '.')
	{
		dprintf(2, "LEFT BOTTOM CORNER ! ############################################\n");
		wave(dna, 0, dna->map.h -1, 120);
	}
	else if (dna->area[dna->map.w - 1][dna->map.h - 1].sign == '.')
	{
		dprintf(2, "RIGHT BOTTOM CORNER ! ############################################\n");
		wave(dna, dna->map.w - 1, dna->map.h - 1, 120);
	}



	//if (lower())



	// else if (tab[1] && dna->area[dna->map.w / 2 + 8][0].sign == '.')
	// {
	// 	dprintf(2, "CLOSE MIDDLE OK ! ############################################\n");
	// 	wave(dna, dna->map.w / 2 + 8, 0, 120);
	// }
}

/*
En fait je devrais faire un algo qui regarde si poser la piece dans une direction
nous fait gagner une plus grande distance que si on essaye vers une autre direction

En gros on a deux direction et on pose la piece au benefice de celle ou on gagnera
le plus de terrain

*/
