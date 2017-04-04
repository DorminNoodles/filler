/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 20:38:55 by lchety            #+#    #+#             */
/*   Updated: 2017/04/04 22:19:26 by lchety           ###   ########.fr       */
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
		x = 0;
		while (x < dna->map.w)
		{
			ft_putchar_fd(dna->map.m[x][y], dna->debug_fd);
			x++;
		}
		y++;
		ft_putchar_fd('\n', dna->debug_fd);
	}
}

void	pars_game(t_fil *dna, char **line)
{
	char **split;
	char *tmp;
	int x;
	int y;

	x = 0;
	y = 0;
	tmp = NULL;
	if ((split = ft_strsplit(*line, ' ')))
	{
		dna->map.w = ft_atoi(split[2]);
		dna->map.h = ft_atoi(split[1]);
	}
	dna->map.m = create_matrice(dna->map.w, dna->map.h);
	del_split(split);
	ft_memdel((void**)line);
	get_next_line(0, line);
	while (y < dna->map.h)
	{
		ft_memdel((void**)line);
		get_next_line(0, line);
		tmp = *line + 4;
		x = 0;
		while (x < dna->map.w)
		{
			dna->map.m[x][y] = *tmp;
			tmp++;
			x++;
		}
		y++;
	}
	debug_show(dna);
}

void	parsing(t_fil *dna, char **line)
{

	if (ft_strstr(*line, "Plateau"))
		pars_game(dna, line);
	ft_putchar_fd('\n', dna->debug_fd);
	ft_putstr_fd(*line, dna->debug_fd);

}
