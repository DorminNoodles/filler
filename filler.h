/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 22:51:53 by lchety            #+#    #+#             */
/*   Updated: 2017/04/26 15:40:24 by lchety           ###   ########.fr       */
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

#define BUFFER_PIECE 64
#define DIAGONALE 90
#define UP 0, -1
#define DOWN 0, 1
#define LEFT -1, 0
#define RIGHT 1, 0
#define CLEAR 0
#define OPEN 1
#define CLOSED 2
#define NEAR_SCORE 2

#define IDLE 0;
#define ATK_PATH 1;

typedef struct s_vect
{
	int x;
	int y;
}t_vect;

typedef struct s_node
{
	t_vect parent;
	t_vect pos;
	int state;
	int ok;
	int g;
	int h;
	int f;
}t_node;

typedef struct	s_case
{
	char sign;
	char path;
	int score;
	int active;
	t_node node;
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

typedef struct s_move
{
	int x;
	int y;
	int score;

}t_move;

typedef struct s_piece
{
		int w;
		int h;
		char tab[BUFFER_PIECE][BUFFER_PIECE];
}t_piece;

typedef struct s_path
{
	t_vect start;
	t_vect aim;
}t_path;

typedef struct		s_fil
{
	int debug_fd;
	int player;
	int startx;
	int starty;
	t_map map;
	t_case **area;
	t_piece piece;
	t_move move;
	int** map_score;
	char enemy_char;
	char player_char;
	t_path path;

}t_fil;



void	init_dna(t_fil *dna);
void	fill_map(t_fil *dna, char **line);
void	parsing(t_fil *dna, char **line);
void	play(t_fil *dna);
char	**create_matrice(int w, int h);
void	del_split(char **split);
int		**create_score_map(t_fil *dna);
void	check_move(t_fil *dna);
void	debug_score_map(t_fil *dna);
void	wave(t_fil *dna, int x, int y, int score);
void	diagonale(t_fil *dna);
void	reset(t_fil *dna);
void	corner(t_fil *dna);
int		check_liberty(t_fil *dna, int x, int y);
void	init_game(t_fil *dna, char **line);
void	get_players(t_fil *dna, char **line);
void	get_map_size(t_fil *dna, char **line);
void	create_area(t_fil *dna, char **line);
void	debug_show_area(t_fil *dna);
t_vect	vect(int x, int y);
int		pathfinding(t_fil *dna, t_vect start, t_vect aim);
void	debug_path_map(t_fil *dna);
int		ft_abs(int x);



#endif
