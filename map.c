/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:42:16 by lchety            #+#    #+#             */
/*   Updated: 2017/04/04 19:03:10 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fill_map(t_fil *dna, char **line)
{
	char *tmp;
	int x;
	int y;

	x = -1;
	y = 0;
	while (y < dna->map.h)
	{
		tmp = *line;
		// ft_putstr_fd("map.h => ", 3);
		ft_putstr_fd(ft_itoa(dna->map.h), 3);
		ft_putstr_fd("mario => ", 3);
		ft_putstr_fd(*line, 3);
		ft_putstr_fd("\n", 3);
		while (++x < dna->map.w)
			dna->map.m[x][y] = *(tmp++);



		// tmp++;
		get_next_line(0, line);
		// ft_putstr_fd("FILLMAP\n", 3);
		y++;
	}
	ft_putstr_fd("END\n", 3);
	ft_putstr_fd(*line, 3);
}
