/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 20:38:55 by lchety            #+#    #+#             */
/*   Updated: 2017/05/03 14:47:45 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		pars_map(t_fil *dna, char **line)
{
	char	*tmp;
	int		x;
	int		y;

	y = 0;
	while (!ft_strstr(*line, "000 "))
	{
		ft_memdel((void**)line);
		get_next_line(0, line);
	}
	while (y < dna->map.h)
	{
		tmp = *line + 4;
		x = -1;
		while (++x < dna->map.w)
		{
			add_piece(dna, x, y, *tmp);
			tmp++;
		}
		y++;
		ft_memdel((void**)line);
		get_next_line(0, line);
	}
	return (1);
}

void	free_tab(char **tab, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		ft_memdel((void**)&tab[i]);
		i++;
	}
	ft_memdel((void**)&tab);
}

int		pars_piece(t_fil *dna, char **line)
{
	char	*tmp;
	int		y;
	int		x;

	y = 0;
	if (!piece_length(dna, line))
		return (0);
	while (y < dna->piece.h)
	{
		ft_memdel((void **)line);
		get_next_line(0, line);
		x = 0;
		tmp = *line;
		while (x < dna->piece.w)
		{
			dna->piece.tab[x][y] = *tmp;
			tmp++;
			x++;
		}
		y++;
	}
	ft_memdel((void **)line);
	return (1);
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

int		get_map_size(t_fil *dna, char **line)
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
			return (0);
		}
	}
	return (1);
}
