/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 20:38:55 by lchety            #+#    #+#             */
/*   Updated: 2017/04/06 21:26:42 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


// void debug_show(t_fil *dna)
// {
// 	int x;
// 	int y;
//
// 	y = 0;
// 	x = 0;
//
// 	while (y < dna->map.h)
// 	{
// 		x = 0;
// 		while (x < dna->map.w)
// 		{
// 			ft_putchar_fd(dna->map.m[x][y], dna->debug_fd);
// 			x++;
// 		}
// 		y++;
// 		ft_putchar_fd('\n', dna->debug_fd);
// 	}
// }
//
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
// void	pars_game(t_fil *dna, char **line)
// {
// 	char **split;
// 	char *tmp;
// 	int x;
// 	int y;
//
// 	ft_putstr_fd("Parsing Game \n", dna->debug_fd);
// 	x = 0;
// 	y = 0;
// 	tmp = NULL;
// 	while (!ft_strstr(*line, "Plateau"))
// 	{
// 		ft_memdel((void**)line);
// 		get_next_line(0, line);
// 	}
// 	if ((split = ft_strsplit(*line, ' ')))
// 	{
// 		dna->map.w = ft_atoi(split[2]);
// 		dna->map.h = ft_atoi(split[1]);
// 	}
// 	dna->map.m = create_matrice(dna->map.w, dna->map.h);
// 	del_split(split);
// 	ft_memdel((void**)line);
// 	get_next_line(0, line);
// 	while (y < dna->map.h)
// 	{
// 		ft_memdel((void**)line);
// 		get_next_line(0, line);
// 		tmp = *line + 4;
// 		x = 0;
// 		while (x < dna->map.w)
// 		{
// 			dna->map.m[x][y] = *tmp;
// 			tmp++;
// 			x++;
// 		}
// 		y++;
// 	}
// 	debug_show(dna);
// }
//
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
// void	parsing(t_fil *dna, char **line)
// {
// 	//ft_putstr_fd(*line, dna->debug_fd);
// 	pars_player(dna, line);
// 	pars_game(dna, line);
// 	pars_piece(dna, line);
// 	// while (!ft_strstr(*line, "Piece"))
// 	// {
// 	// 	ft_memdel((void**)line);
// 	// 	get_next_line(0, line);
// 	// }
// 	//pars_piece(dna, line);
// 	// ft_putchar_fd('\n', dna->debug_fd);
// 	//ft_putstr_fd(*line, dna->debug_fd);
// 	ft_putstr_fd("EXIT_PARSING\n", dna->debug_fd);
// }

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
