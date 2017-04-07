/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 22:51:53 by lchety            #+#    #+#             */
/*   Updated: 2017/04/07 01:19:36 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <limits.h>
#include <signal.h>
#include "libft.h"
#include "get_next_line.h"

typedef struct	s_case
{
	char sign;
	int score;
	int active;

}t_case;

typedef struct s_bloc
{
	int x;
	int y;
}t_bloc;

typedef struct s_map
{
		int w;
		int h;
}t_map;

typedef struct s_piece
{
		int w;
		int h;
		char **m;
}t_piece;

typedef struct		s_fil
{
	int debug_fd;
	int player;
	t_map map;
	t_case **area;
	t_piece piece;
	int** map_score;
	char enemy_char;
	char player_char;

}t_fil;



void	init_dna(t_fil *dna);
void	fill_map(t_fil *dna, char **line);
void	parsing(t_fil *dna, char **line);
void	play();
char	**create_matrice(int w, int h);
void	del_split(char **split);
int		**create_score_map(t_fil *dna);

#endif
