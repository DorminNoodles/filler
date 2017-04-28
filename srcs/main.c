/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 22:47:17 by lchety            #+#    #+#             */
/*   Updated: 2017/04/28 14:48:19 by lchety           ###   ########.fr       */
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

// char	**create_matrice(int w, int h)
// {
// 	char **plato;
// 	int x;
//
// 	x = -1;
// 	plato = NULL;
// 	if(!(plato = (char**)ft_memalloc(sizeof(char*) * w)))
// 		exit(EXIT_FAILURE);
// 	while (++x < w)
// 	{
// 		if(!(*(plato + x) = (char*)ft_memalloc(sizeof(char) * h)))
// 			exit(EXIT_FAILURE);
// 	}
// 	return (plato);
// }

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
