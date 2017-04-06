/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 01:01:29 by lchety            #+#    #+#             */
/*   Updated: 2017/04/06 19:27:38 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


// int		**malloc_map(int w, int h)
// {
// 	int	**map;
// 	int		x;
// 	int		y;
//
// 	ft_putstr_fd("Create matrice\n", 3);
// 	x = -1;
// 	map = NULL;
//
// 	if(!(map = (int**)ft_memalloc(sizeof(int*) * w)))
// 		exit(EXIT_FAILURE);
// 	while (++x < w)
// 	{
// 		if(!(*(map + x) = (int*)ft_memalloc(sizeof(int) * h)))
// 			exit(EXIT_FAILURE);
// 		y = -1;
// 		while (++y < h)
// 			map[x][y] = -1;
// 	}
// 	return (map);
// }
//
// int		**create_score_map(t_fil *dna)
// {
// 	int x;
// 	int y;
// 	int **score;
//
// 	y = 0;
// 	//dprintf(dna->debug_fd, "fuck you ===> %c\n", dna->enemy_char);
// 	// //pas oublier de free
// 	score = malloc_map(dna->map.w, dna->map.h);
// 	while (y < dna->map.h)
// 	{
// 		//dprintf(dna->debug_fd, "fuck you ===> %c\n", dna->enemy_char);
// 		x = 0;
// 		while(x < dna->map.w)
// 		{
// 			if(dna->map.m[x][y] == dna->enemy_char)
// 				score[x][y] = 0;
// 			x++;
// 		}
// 		y++;
//  	}
//
// 	y = 0;
// 	while (y < dna->map.h)
// 	{
// 		dprintf(2, "fuck you HA HA ===> %d\n", y);
//
// 		x = 0;
// 		while (x < dna->map.w)
// 		{
// 			// if (score[x][y] < score[x][y])
// 			// 	printf("test");
// 			// 	dprintf(dna->debug_fd, "ZZZZZZ ===> %d\n", y);
//
// 				//score[x + 1][y] = score[x][y] - 1;
// 			// if (score[x - 1][y] < score[x][y])
// 			// 	score[x - 1][y] = score[x][y] - 1;
// 			// if (score[x][y + 1] < score[x][y])
// 			// 	score[x][y + 1] = score[x][y] - 1;
// 			// if (score[x][y - 1] < score[x][y])
// 			// 	score[x][y - 1] = score[x][y] - 1;
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (score);
// }
//
// int		pose_piece(v2d origin)
// {
// 	int error;
// 	int contact;
// 	int score
//
// 	while (y < dna->piece.h)
// 	{
// 		while (x < dna->piece.w)
// 		{
// 			if piece[x][y] == '*'
// 			{
// 				if (map[origin.x + x][origin.y + y] == ennemy_sign)
// 					error = 1;
//
// 				if (map[origin.x + x][origin.y + y] == player_sign)
// 					contact++;
//
// 					//map limits
// 				if (origin.x + x > map.w || origin.y + y > map.w )
// 					error = 1
//
// 				score += score_map[x][y];
// 			}
// 		}
//
// 	}
// 	if score > dna->bestmove->score
// 		dna->best.score = score;
// 		dna->best.x = origin.x;
// 		dna->best.x = origin.y;
//
// 	if(contact == 1 && !error)
// 		return (1);
// 	return(0);
//
// }
//
// void	piece_tester()
// {
//
// 	while
// 	{
// 		while()
// 		{
// 			pose_piece();
//
// 		}
//
// 	}
//
//
// }
