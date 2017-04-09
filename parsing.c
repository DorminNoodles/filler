/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 20:38:55 by lchety            #+#    #+#             */
/*   Updated: 2017/04/09 02:14:28 by lchety           ###   ########.fr       */
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
		dprintf(2, "y => %d\n", y);
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
		dprintf(2, "y => %d\n", y);
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

void	make_square(t_fil *dna, int x, int y, int size, int score)
{
	int i;

	i = 0;
	//up
	while (i < size)
	{
		if (x + i >= 0 && x + i < dna->map.w && y >= 0)
		{
			dprintf(2, "x => %d    y => %d \n", x, y);
			dna->area[x + i][y].score = score;
		}
		if (x + i >= 0 && x + i < dna->map.w && y + size - 1 < dna->map.h)
		{
			dna->area[x + i][y + size - 1].score = score;
		}
		i++;
	}
	i = 0;
	//left

	//right

	//down

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

	while (i < size)
	{
		// dprintf(2, "1/2 = %d\n", 1/2);
		make_square(dna, x - i, y - i, (i * 2) + 1, score - i);
		i++;

		//1 * 2 + 1 = 3
		//2 * 2 + 1 = 5
		//3*2+1 = 7
		// tmp = x - (size/2);
		// if (tmp + i < dna->map.w && tmp >= 0)
		// 	dna->area[x - (size/2) + i][y].sign = '4';
		// i++;
	}



}

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
		dprintf(2, "new piece !\n");
		dna->area[x][y].sign = dna->enemy_char;
		dna->area[x][y].score = 50;
		wave(dna, x, y, 50);

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

	ft_putstr_fd("Parsing Map \n", dna->debug_fd);
	x = 0;
	y = 0;
	i = 0;
	tmp = NULL;
	while (i < 1)
	{
		ft_memdel((void**)line);
		get_next_line(0, line);
		i++;
	}
	//dprintf(2, "%s\n", *line);
	while (y < dna->map.h)
	{
		ft_memdel((void**)line);
		get_next_line(0, line);
		tmp = *line + 4;
		x = 0;
		while (x < dna->map.w)
		{
			add_piece(dna, x, y, *tmp);
			tmp++;
			x++;
		}
		y++;
		//dprintf(2, "TEST\n");
	}
	debug_show(dna);
	debug_show_2(dna);
}

// void	pars_piece(t_fil *dna, char **line)
// {
// 	char **split;
// 	char *tmp;
// 	int y;
// 	int x;
//
// 	y = 0;
// 	x = 0;
//
// 	ft_putstr_fd("Parsing Piece \n", dna->debug_fd);
// 	while (!ft_strstr(*line, "Piece"))
// 	{
// 		ft_memdel((void**)line);
// 		get_next_line(0, line);
// 	}
// 	if ((split = ft_strsplit(*line, ' ')))
// 	{
// 		dna->piece.w = ft_atoi(split[2]);
// 		dna->piece.h = ft_atoi(split[1]);
// 	}
//
// 	ft_putstr_fd("p.w =>", dna->debug_fd);
// 	ft_putstr_fd(ft_itoa(dna->piece.w), dna->debug_fd);
// 	ft_putstr_fd("\n", dna->debug_fd);
// 	ft_putstr_fd("p.h =>", dna->debug_fd);
// 	ft_putstr_fd(ft_itoa(dna->piece.h), dna->debug_fd);
// 	ft_putstr_fd("\n", dna->debug_fd);
// 	dna->piece.m = create_matrice(dna->piece.w, dna->piece.h);
// 	del_split(split);
// 	while (y < dna->piece.h)
// 	{
// 		ft_memdel((void **)line);
// 		get_next_line(0, line);
// 		x = 0;
// 		tmp = *line;
// 		while (x < dna->piece.w)
// 		{
// 			dna->piece.m[x][y] = *tmp;
// 			// ft_putchar_fd(*tmp, dna->debug_fd);
// 			tmp++;
// 			x++;
// 		}
// 		//ft_putchar_fd('\n', dna->debug_fd);
// 		y++;
// 	}
// 	debug_show_piece(dna);
//
// }
//
// void	pars_player(t_fil *dna, char **line)
// {
// 	dprintf(dna->debug_fd, "HAAAAAAAAAAAAAHAHAHAHAHAHAH\n", dna->enemy_char);
// 	if (ft_strstr(*line, "exec p1"))
// 	{
// 		dna->player = 1;
// 		dna->player_char = 'O';
// 		dna->enemy_char = 'X';
// 	}
// 	else if (ft_strstr(*line, "exec p2"))
// 	{
// 		dna->player = 2;
// 		dna->player_char = 'X';
// 		dna->enemy_char = 'O';
// 	}
// }
//
void	parsing(t_fil *dna, char **line)
{
	//ft_putstr_fd(*line, dna->debug_fd);
	// pars_player(dna, line);
	pars_map(dna, line);
	// pars_game(dna, line);
	// pars_piece(dna, line);
	// while (!ft_strstr(*line, "Piece"))
	// {
	// 	ft_memdel((void**)line);
	// 	get_next_line(0, line);
	// }
	//pars_piece(dna, line);
	// ft_putchar_fd('\n', dna->debug_fd);
	//ft_putstr_fd(*line, dna->debug_fd);
	ft_putstr_fd("EXIT_PARSING\n", dna->debug_fd);
}

/*
	hum..... je dois faire cette putain de boucle avec get_next_line
	pour regarder en permanence si on ecrit sur l STDIN....

	Ensuite je dois parser PARSER !!!! parser a mort...

	Le probleme est de verifier si on m envoi pas de la merde...

	Mais comment faire vu que je lis ligne par ligne... je peux verifier
	l integrite d une ligne avant d en faire quelque chose...

	Donc premier probleme gerer les erreurs

	Second probleme condition d entree pour le parsing et pour le play

	L ideal serait de commencer a parser la map quand je tombe sur Plateau
	et commencer a parser la Piece si je tombe sur le mot Piece...

	Mais quand jouer ? Quand j ai une map et une piece ?

	Il y a deux facon de voir les choses, soit quand la vm envoi quelque chose sur l STDIN elle envoi tout et on parse en sachant qu on va trouver tel truc a tel endroit

	ou

	elle envoi tout mais on regarde ligne par ligne si on a bien ce qu on attend...

	La main while avec le gnl detecte quand on nous a tout enoye et ensuite on parser
	donc on entre qu une fois par movement dans la main while
	on fait quun tour de la mainwhile

	soit on en fait plusieurs mais comment savoir si on est a la fin puisque gnl va attendre a la fin....

	donc vaut mieux rentrer qu une fois dns main while je pense....

	donc je fais le parsing simplement sans gestion d erreur

	ensuite je fais l algo pour jouer

	et ensuite je reviens sur le parsing et je gere les erreurs

*/
