/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 20:38:55 by lchety            #+#    #+#             */
/*   Updated: 2017/04/27 17:53:10 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


void debug_show(t_fil *dna)
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
			// dprintf(2, "%c", dna->area[x][y].sign);
			dprintf(2, "%3d", dna->area[x][y].score);
			x++;
		}
		dprintf(2, "\n");
		y++;
		// ft_putchar_fd('\n', 2);
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

// void debug_show_piece(t_fil *dna)
// {
// 	int x;
// 	int y;
//
// 	y = 0;
// 	x = 0;
//
// 	while (y < dna->piece.h)
// 	{
// 		//ft_putstr_fd("va chier", dna->debug_fd);
// 		x = 0;
// 		while (x < dna->piece.w)
// 		{
// 			ft_putchar_fd(dna->piece.m[x][y], dna->debug_fd);
// 			x++;
// 		}
// 		y++;
// 		ft_putchar_fd('\n', dna->debug_fd);
// 	}
// }
//
// void	runny(t_fil *dna, int x, int y, int score)
// {
// 	dna->area[x][y].score = score;
// 	if (x - 1 >= 0 && score > dna->area[x - 1][y].score)
// 		runny(dna, x - 1, y, score - 1);
//
// 	if (x + 1 < dna->map.w && score > dna->area[x + 1][y].score)
// 		runny(dna, x + 1, y, score - 1);
//
// 	if (y - 1 >= 0 && score > dna->area[x][y - 1].score)
// 		runny(dna, x, y - 1, score - 1);
//
// 	if (y + 1 < dna->map.h && score > dna->area[x][y + 1].score)
// 		runny(dna, x, y + 1, score - 1);
//
// 	// if (dna->area[x][y].active)
// 	// 	dna->area[x][y].score = score;
// 	// else
// 	// 	dna->area[x][y].score = 0;
// 	// if (x - 1 >= 0 && dna->area[x - 1][y].active && dna->area[x - 1][y].score < score)
// 	// 	runny(dna, x - 1, y, dna->area[x - 1][y].score - 1);
// }





//je veux dessiner un carre dont l origine est son centre en gros
//les coordonnes x et y sont toujours les memes  mais j ai besoin d avoir la position de la premiere ligne en x et y

//
// donc si mon point d origine est 0,0
// et que mon carre fait 4 de taille
// je vais faire 4/2 = 2
// et x - 2 = -2,0
//
// donc -2,0
//
// ensuite je vais tracer le trait jusqu a atteindre la size
//
// -2 + 0 + 1 + 2
//
// la fin du trait sera en 1,0
// parce que la taille est 4 et que j ai -2, -1, 0, 1
//
// donc tant que i <= 1
//
// -2 + 4 = 2

void	add_piece(t_fil *dna, int x, int y, char c)
{
	// dprintf(2, "add_piece\n");
	if (dna->area[x][y].sign != c && c == dna->enemy_char)
	{
		//dprintf(2, "new piece !\n");
		dna->area[x][y].sign = dna->enemy_char;
		//dna->area[x][y].score = 50;
		//wave(dna, x, y, 50);
	}
	if (dna->area[x][y].sign != c && c == dna->player_char)
	{
		//dprintf(2, "new piece !\n");
		dna->area[x][y].sign = dna->player_char;
		//dna->area[x][y].score = 0;

	}
	// dna->area[x][y].sign = c;
}

void	pars_map(t_fil *dna, char **line)
{
	char **split;
	char *tmp;
	int i;
	int x;
	int y;

	x = 0;
	y = 0;
	i = 0;
	tmp = NULL;
	while (!ft_strstr(*line, "000 "))
	{
		ft_memdel((void**)line);
		get_next_line(0, line);
		i++;
	}
	while (y < dna->map.h)
	{
		tmp = *line + 4;
		// dprintf(2, "x => %d\n", x);
		// dprintf(2, "y => %d\n", y);
		//dprintf(2, "tmp => %s\n", tmp);
		x = 0;
		while (x < dna->map.w)
		{

			// dprintf(2, "Segfault here 2\n");
			add_piece(dna, x, y, *tmp);
			// dprintf(2, "Segfault here 3\n");
			tmp++;
			x++;
		}
		y++;
		//dprintf(2, "TEST\n");
		ft_memdel((void**)line);
		get_next_line(0, line);
	}
}

void	pars_piece(t_fil *dna, char **line)
{
	char **split;
	char *tmp;
	int y;
	int x;

	y = 0;
	x = 0;

	while (!ft_strstr(*line, "Piece"))
	{
		ft_memdel((void**)line);
		get_next_line(0, line);
	}
	if ((split = ft_strsplit(*line, ' ')))
	{
		dna->piece.w = ft_atoi(split[2]);
		dna->piece.h = ft_atoi(split[1]);
	}
	ft_memdel((void**)&split[0]);
	ft_memdel((void**)&split[1]);
	ft_memdel((void**)&split[2]);
	ft_memdel((void**)&split);
	while (y < dna->piece.h)
	{
		ft_memdel((void **)line);
		get_next_line(0, line);
		x = 0;
		tmp = *line;
		while (x < dna->piece.w)
		{

			dna->piece.tab[x][y] = *tmp;
			// dprintf(2, "%c", *tmp);
			tmp++;
			x++;
		}
		// dprintf(2, "\n");
		//ft_putchar_fd('\n', dna->debug_fd);
		y++;
	}
	// debug_show_piece(dna);
	ft_memdel((void **)line);
}

void	start_pos(t_fil *dna)
{
	int x;
	int y;
	int find;

	y = 0;
	x = 0;
	find = 0;

	if (dna->startx != 0 && dna->starty != 0)
		return;

	while (y < dna->map.h && !find)
	{
		x = 0;
		while (x < dna->map.w && !find)
		{
			if (dna->area[x][y].sign == dna->player_char)
			{
				dna->startx = x;
				dna->starty = y;
				find = 1;
			}
			x++;
		}
		y++;
	}
}

void	parsing(t_fil *dna, char **line)
{
	char *test;

	// test = (char*)malloc(300);
	pars_map(dna, line);

	pars_piece(dna, line);


	start_pos(dna);
}
