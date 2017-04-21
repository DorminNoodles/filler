/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:57:16 by lchety            #+#    #+#             */
/*   Updated: 2017/04/21 17:54:16 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// void	add_open(t_fil *dna, t_vect s)
// {
//
// }
//
// void	init_node()
// {
//
//
// }
//
// void	update_open(t_fil *dna, int cur_pos)
// {
// 	t_node lst[8];
//
// 	init_node(lst, &lst);
//
// }
//
// void	pathfinding(t_fil *dna)
// {
// 	t_node open[USHRT_MAX];
// 	t_vect cur_pos;
//
// 	cur_pos.x = dna->fromx;
// 	cur_pos.y = dna->fromy;
//
// 	update_open(dna, cur_pos);
//
// }

int		manhattan(t_vect a, t_vect b)
{
	return ((b.x - a.x) + (b.y - b.y));
}

int		node_ok(t_fil *dna, t_vect cur, t_vect dir)
{
	int x;
	int y;

	x = cur.x + dir.x;
	y = cur.y + dir.y;

	if (y < 0 && y >= dna->map.h && x < 0 && x >= dna->map.w)
		return (0);
	if (dna->area[x][y].sign == dna->enemy_char)
		return (0);
	return (1);
}

void	check_nodes(t_fil *dna, t_vect cur, t_node *tmp)
{
	if (node_ok(dna, cur, vect(0, -1)))
	{
		tmp[0].ok = 1;
		tmp[0].pos.x = cur.x;
		tmp[0].pos.y = cur.y - 1;
		dna->area[cur.x][cur.y - 1].path = '#';
	}
	if (node_ok(dna, cur, vect(0, 1)))
	{
		tmp[1].ok = 1;
		tmp[1].pos.x = cur.x;
		tmp[1].pos.y = cur.y + 1;
		dna->area[cur.x][cur.y + 1].path = '#';
	}
	if (node_ok(dna, cur, vect(-1, 0)))
	{
		tmp[2].ok = 1;
		tmp[2].pos.x = cur.x - 1;
		tmp[2].pos.y = cur.y;
		dna->area[cur.x - 1][cur.y].path = '#';
	}
	if (node_ok(dna, cur, vect(1,0)))
	{
		tmp[3].ok = 1;
		tmp[3].pos.x = cur.x + 1;
		tmp[3].pos.y = cur.y;
		dna->area[cur.x + 1][cur.y].path = '#';
	}
}

void	init_nodes(t_node *tmp)
{
	int i;

	i = 0;
	while (i < 8)
	{
		tmp[i].ok = 0;
		tmp[i].g = 0;
		tmp[i].h = 0;
		tmp[i].f = 0;
		i++;
	}
}

int		cost_g(t_fil *dna, t_node *node)
{
	int res;

	res = 0;

	res = (node->pos.x - dna->from.x) + (node->pos.y - dna->from.y);

	//dprintf(2, "TESTTTTTT +> %d\n", res);

	return (res);
}

int		cost_h(t_fil *dna, t_node *node)
{
	int res;

	res = 0;

	res = (node->pos.x - dna->goal.x) + (node->pos.y - dna->goal.y);

	//dprintf(2, "TESTTTTTT +> %d\n", res);

	return (res);
}

void	nodes_cost(t_fil *dna, t_node *tmp)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tmp[i].ok)
		{
			tmp[i].g = cost_g(dna, tmp + i);
			tmp[i].h = cost_h(dna, tmp + i);
			tmp[i].f = tmp[i].g + tmp[i].h;
			// dprintf(2, "TEST F SCORE => %d\n", tmp[i].f);
			// dprintf(2, "TEST G SCORE => %d\n", tmp[i].g);
			// dprintf(2, "TEST H SCORE => %d\n", tmp[i].h);
		}
		i++;
	}
}
//
// void	pathfinding(t_fil *dna)
// {
// 	t_node	open[USHRT_MAX];
// 	t_node	closed[USHRT_MAX];
// 	t_node	tmp_node[8];
//
// 	t_vect cur;
//
// 	init_nodes(tmp_node);
//
// 	dna->goal = vect(2, 2);
// 	dna->from.x = 12;
// 	dna->from.y = 12;
// 	dna->area[dna->from.x][dna->from.y].path = 'A';
//
// 	cur.x = dna->from.x;
// 	cur.y = dna->from.y;
//
// 	check_nodes(dna, cur, tmp_node);
// 	nodes_cost(dna, tmp_node);
// 	add_open(dna, tmp_node);
//
// 	debug_path_map(dna);
// }

int		count_g(int score, t_vect parent ,t_vect pos)
{
	if (pos.x != parent.x && pos.y != parent.y)
		return (score + 14);
	else
		return (score + 10);
}

int		count_h(t_vect parent, t_vect cur)
{
	return (manhattan(parent, cur));
}

int		count_f(t_fil *dna, t_vect pos, t_vect parent)
{
	int score;

	score = dna->area[parent.x][parent.y].node.g;
	//calculer f grace a g et h
	return (count_g(score, parent, pos) + count_h(parent, pos));
}



int		check_node(t_fil *dna, t_vect parent, t_vect dir)
{
	int score;
	int x;
	int y;

	x = parent.x + dir.x;
	y = parent.y + dir.y;
	score = 0;

	if (x >= 0 && x < dna->map.w && y >= 0 && y < dna->map.h)
		return (0);
	if (dna->area[x][y].sign == dna->enemy_char)
		return (0);
	if (dna->area[x][y].node.state == CLOSED)
		return (0);
	if (dna->area[x][y].node.state == OPEN)
	{
		score = count_f(dna, vect(x, y), parent);
		return (0);
		//dprintf(2, "MONGO => %d\n", dna->area[x][y].node.g);
	}

	return (1);
}

void	add_open(t_fil *dna, t_vect parent, t_vect dir)
{
	int x;
	int y;

	x = parent.x + dir.x;
	y = parent.y + dir.y;
	dna->area[x][y].node.state = OPEN;
	dna->area[x][y].node.f = count_f(dna, pos, pos);
}

void	near_nodes(t_fil *dna, t_node *tmp, t_vect parent)
{
	if (check_node(dna, parent, vect(UP)))
		add_open(dna, parent, vect(UP));
	check_node(dna, parent, vect(DOWN));
	{
		tmp[1].state = OPEN;
		tmp[1].pos.x = parent.x;
		tmp[1].pos.y = parent.y + 1;
	}
	check_node(dna, parent, vect(LEFT));
	{
		tmp[2].state = OPEN;
		tmp[2].pos.x = parent.x - 1;
		tmp[2].pos.y = parent.y;
	}
	check_node(dna, parent, vect(RIGHT));
	{
		tmp[3].state = OPEN;
		tmp[3].pos.x = parent.x + 1;
		tmp[3].pos.y = parent.y;
	}
}

void	pathfinding(t_fil *dna)
{
	t_node tmp[4];
	t_vect cur;

	cur.x = dna->from.x;
	cur.y = dna->from.y;

	//trouver les noeuds proches et les mettre en openlist
	near_nodes(dna, tmp, cur);

	//dprintf(2, "KONG => %d\n", tmp[0].state);

	//recalculer tous les noeuds dans open ou garder une liste des nouveaux
	//et faire les updates quand necessaire



	//cur = best_node(dna, cur);

}
