/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 22:47:17 by lchety            #+#    #+#             */
/*   Updated: 2017/04/04 22:20:30 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	**parse_matrice(int w, int h, char **matrice)
{



	return (NULL);
}

void	get_map(t_fil *map)
{


}

char	**create_matrice(int w, int h)
{
	char **plato;
	int x;

	ft_putstr_fd("Create matrice\n", 3);
	x = -1;
	plato = NULL;

	plato = (char**)ft_memalloc(sizeof(char*) * w);
	while (++x < w)
		*(plato + x) = (char*)ft_memalloc(sizeof(char) * h);
	return (plato);
}

int		main(void)
{
	t_fil dna;
	int fd;
	char *line;
	char **split;
	char **plato;

	line = NULL;
	plato = NULL;
	init(&dna);
	dna.debug_fd = open("file_out", O_WRONLY);

	while (get_next_line(0, &line))
	{
		parsing(&dna, &line);
		play();
		free(line);
	}
	close(fd);
	return (0);
}
