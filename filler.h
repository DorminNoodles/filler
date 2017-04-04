/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 22:51:53 by lchety            #+#    #+#             */
/*   Updated: 2017/04/04 21:29:13 by lchety           ###   ########.fr       */
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
#include "libft.h"
#include "get_next_line.h"

typedef	struct s_bloc
{
	int x;
	int y;
}t_bloc;

typedef struct s_map
{
		int w;
		int h;
		char **m;
}t_map;

typedef struct s_piece
{
		int w;
		int h;
		char **matrice;
}t_piece;

typedef struct		s_plato
{
	int w;
	int h;
	char **map;
}t_plato;

typedef struct		s_fil
{
	int debug_fd;
	int player;
	t_plato *plato;
	t_map map;

}t_fil;



void	init(t_fil *dna);
void	fill_map(t_fil *dna, char **line);
void	parsing(t_fil *dna, char **line);
void	play();
char	**create_matrice(int w, int h);
void	del_split(char **split);

#endif
