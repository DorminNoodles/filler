/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 20:38:55 by lchety            #+#    #+#             */
/*   Updated: 2017/04/28 14:50:26 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	add_piece(t_fil *dna, int x, int y, char c)
{
	// dprintf(2, "add_piece\n");
	if (dna->map.area[x][y].sign != c && c == dna->enemy_char)
	{
		//dprintf(2, "new piece !\n");
		dna->map.area[x][y].sign = dna->enemy_char;
		//dna->area[x][y].score = 50;
		//wave(dna, x, y, 50);
	}
	if (dna->map.area[x][y].sign != c && c == dna->player_char)
	{
		//dprintf(2, "new piece !\n");
		dna->map.area[x][y].sign = dna->player_char;
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
		y++;
	}
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
			if (dna->map.area[x][y].sign == dna->player_char)
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

void	get_players(t_fil *dna, char **line)
{
	if (ft_strstr(*line, "exec p1"))
	{
		dna->player = 1;
		dna->player_char = 'O';
		dna->enemy_char = 'X';
	}
	else if (ft_strstr(*line, "exec p2"))
	{
		dna->player = 2;
		dna->player_char = 'X';
		dna->enemy_char = 'O';
	}
}

void	get_map_size(t_fil *dna, char **line)
{
	char **split;

	while (!ft_strstr(*line, "Plateau"))
	{
		ft_memdel((void**)line);
		get_next_line(0, line);
	}
	if ((split = ft_strsplit(*line, ' ')))
	{
		if (split[2] && split[1])
		{
			dna->map.w = ft_atoi(split[2]);
			dna->map.h = ft_atoi(split[1]);
			ft_memdel((void**)&split[0]);
			ft_memdel((void**)&split[1]);
			ft_memdel((void**)&split[2]);
			ft_memdel((void**)&split);
		}
		else
		{
			ft_putstr_fd("Error parsing map size\n", 2);
			exit (EXIT_FAILURE);
		}
	}
}

void	parsing(t_fil *dna, char **line)
{
	char *test;

	pars_map(dna, line);

	pars_piece(dna, line);


	start_pos(dna);
}
