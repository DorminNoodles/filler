/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 22:47:17 by lchety            #+#    #+#             */
/*   Updated: 2017/05/01 13:41:34 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	create_area(t_fil *dna, char **line)
{
	int	x;
	int	y;
	t_case **area;

	x = 0;
	if(!(area = (t_case**)ft_memalloc(sizeof(t_case*) * dna->map.w)))
		exit(EXIT_FAILURE);
	while (x < dna->map.w)
	{
		if(!(*(area + x) = (t_case*)ft_memalloc(sizeof(t_case) * dna->map.h)))
			exit(EXIT_FAILURE);
		y = 0;
		while (y < dna->map.h)
		{
			area[x][y].sign = '.';
			area[x][y].score = 0;
			y++;
		}
		x++;
	}
	dna->map.area = area;
}

int		main(void)
{
	t_fil dna;
	int fd;
	char *line;
	char **split;

	line = NULL;
	dna.map.area = NULL;
	while (get_next_line(0, &line))
	{
		if (!dna.map.area)
			init_game(&dna, &line);
		reset(&dna);
		parsing(&dna, &line);
		play(&dna);
	}
	close(fd);
	return (0);
}
