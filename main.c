/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 22:47:17 by lchety            #+#    #+#             */
/*   Updated: 2017/04/27 17:39:37 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void debug_show_area(t_fil *dna)
{
	int x;
	int y;

	x = 0;
	y = 0;

	ft_putstr_fd("DEBUG_SHOW_AREA\n", 2);
	while (y < dna->map.h)
	{
		x = 0;
		while (x < dna->map.w)
		{
			dprintf(2, "%4d", dna->area[x][y].score);
			// dprintf(2, "%c", dna->area[x][y].sign);
			x++;
		}
		y++;
		dprintf(2, "\n");
	}
}

char	**parse_matrice(int w, int h, char **matrice)
{



	return (NULL);
}

void	get_map(t_fil *map)
{


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

void	create_area(t_fil *dna, char **line)
{
	int	x;
	int	y;
	t_case **area;

	x = 0;
	// ft_putstr_fd("Create_Area\n", 2);
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
			area[x][y].active = 1;
			area[x][y].path = '.';
			area[x][y].node.state = CLEAR;
			area[x][y].node.g = 0;
			area[x][y].node.h = 0;
			area[x][y].node.f = 0;
			// dprintf(2, "Taratata\n");
			y++;
		}
		x++;
	}
	dna->area = area;
}

char	**create_matrice(int w, int h)
{
	char **plato;
	int x;

	// ft_putstr_fd("Create matrice\n", 2);
	x = -1;
	plato = NULL;

	if(!(plato = (char**)ft_memalloc(sizeof(char*) * w)))
		exit(EXIT_FAILURE);
	while (++x < w)
	{
		if(!(*(plato + x) = (char*)ft_memalloc(sizeof(char) * h)))
			exit(EXIT_FAILURE);
	}
	return (plato);
}

void display_segfault(int sig)
{
	if (sig == SIGSEGV)
	{
		// ft_putstr_fd("[SEGFAULT CUSTOM]\n", 2);
		exit(EXIT_FAILURE);
	}

}

int		main(void)
{
	t_fil dna;
	int fd;
	char *line;
	char **split;

	signal(SIGSEGV, display_segfault);

	line = NULL;
	dna.area = NULL;
	// test = (char*)malloc(600);
	//dna.debug_fd = open("file_out", O_WRONLY);
	while (get_next_line(0, &line))
	{
		// dprintf(2, "Search segfault 1\n");
		if (!dna.area)
			init_game(&dna, &line);
		reset(&dna);
		// debug_score_map(&dna);
		// dprintf(2, "test w=> %d\n", dna.map.w);
		// dprintf(2, "test h=> %d\n", dna.map.h);
		// dprintf(2, "test player=> %d\n", dna.player);
		parsing(&dna, &line);
		// dprintf(2, "Search segfault 2\n");
		//dprintf(2, "Bart => %c\n", dna.area[38][5].path);
		play(&dna);

		// free(line);
		//ft_memdel((void**)&line);
	}
	close(fd);
	return (0);
}
