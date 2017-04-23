/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:57:16 by lchety            #+#    #+#             */
/*   Updated: 2017/04/23 21:10:06 by lchety           ###   ########.fr       */
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

int		ft_abs(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}

int		manhattan(t_vect a, t_vect b)
{
	int distance;

	// dprintf(2, "distance x => %d\n", b.x - a.x);
	// dprintf(2, "distance y => %d\n", b.y - a.y);

	distance = ft_abs(b.x - a.x) + ft_abs(b.y - a.y);
	// if (distance < 0)
	// 	distance *= -1;
	// dprintf(2, "Manhattan distance = %d\n", distance);
	return (distance);
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

// void	check_nodes(t_fil *dna, t_vect cur, t_node *tmp)
// {
// 	if (node_ok(dna, cur, vect(0, -1)))
// 	{
// 		tmp[0].ok = 1;
// 		tmp[0].pos.x = cur.x;
// 		tmp[0].pos.y = cur.y - 1;
// 		dna->area[cur.x][cur.y - 1].path = '#';
// 	}
// 	if (node_ok(dna, cur, vect(0, 1)))
// 	{
// 		tmp[1].ok = 1;
// 		tmp[1].pos.x = cur.x;
// 		tmp[1].pos.y = cur.y + 1;
// 		dna->area[cur.x][cur.y + 1].path = '#';
// 	}
// 	if (node_ok(dna, cur, vect(-1, 0)))
// 	{
// 		tmp[2].ok = 1;
// 		tmp[2].pos.x = cur.x - 1;
// 		tmp[2].pos.y = cur.y;
// 		dna->area[cur.x - 1][cur.y].path = '#';
// 	}
// 	if (node_ok(dna, cur, vect(1,0)))
// 	{
// 		tmp[3].ok = 1;
// 		tmp[3].pos.x = cur.x + 1;
// 		tmp[3].pos.y = cur.y;
// 		dna->area[cur.x + 1][cur.y].path = '#';
// 	}
// }

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

int		count_g(t_fil *dna, t_vect parent ,t_vect pos)
{
	int score_parent;

	score_parent = dna->area[parent.x][parent.y].node.g;
	// dprintf(2, "score_parent => %d\n", score_parent);
	if (pos.x != parent.x && pos.y != parent.y)
		return (score_parent + 14);
	else
		return (score_parent + 10);
}

int		count_h(t_vect pos, t_vect goal)
{
	// dprintf(2, "COUNT_H x%d  y%d\n", pos.x, pos.y);
	return (manhattan(pos, goal) * 10);
}



int		check_node(t_fil *dna, t_vect parent, t_vect dir)
{
	int score;
	int x;
	int y;

	x = parent.x + dir.x;
	y = parent.y + dir.y;
	score = 0;

	// dprintf(2, "CHECK NODE\n");

	// dprintf(2, "Fuck You => x %d, y %d\n", x, y);
	if (x < 0 || x >= dna->map.w || y < 0 || y >= dna->map.h)
		return (0);
	// dprintf(2, "TEST CHECK NODE\n");
	if (dna->area[x][y].sign == dna->enemy_char)
	{
		dna->area[x][y].path = '+';
		return (0);
	}
	// dprintf(2, "TEST CHECK NODE 2\n");
	if (dna->area[x][y].node.state == CLOSED)
		return (0);
	// dprintf(2, "TEST CHECK NODE 3\n");
	if (dna->area[x][y].node.state == OPEN)
	{
		dprintf(2, "ALREADY OPEN !\n");
		return (0);
		//dprintf(2, "MONGO => %d\n", dna->area[x][y].node.g);
	}
	// dprintf(2, "TEST CHECK NODE 4\n");

	return (1);
}

//on push le node a ajouter dans openlist et on calcul egalement ses
//couts (en fait on passe son statut a OPEN)
void	add_open(t_fil *dna, t_vect parent, t_vect dir)
{
	int x;
	int y;
	int  score_g;


	score_g = dna->area[parent.x][parent.y].node.g;
	score_g = (dir.x != 0 && dir.y != 0) ? 14 : 10;

	// dprintf(2, "ADD FUCKING OPEN !\n");

	x = parent.x + dir.x;
	y = parent.y + dir.y;
	// dprintf(2, "X %d  ,  Y %d\n", parent.x, parent.y);
	dna->area[x][y].node.state = OPEN;
	dna->area[x][y].node.g = count_g(dna, parent, vect(x, y));
	// dprintf(2, "COUNT_H A x%d  y%d\n", x, y);
	// dprintf(2, "COUNT_H B x%d  y%d\n", dna->goal.x, dna->goal.y);
	dna->area[x][y].node.h = count_h(vect(x, y), dna->goal);
	// dprintf(2, "count h = > %d\n", dna->area[x][y].node.h);
	// dprintf(2, "F_score => %d\n", dna->area[x][y].node.f);
	dna->area[x][y].node.f = dna->area[x][y].node.g + dna->area[x][y].node.h;

	dprintf(2, "--------------------------------------------ALL SCORES\n");
	dprintf(2, "H_score => %d\n", dna->area[x][y].node.h);
	dprintf(2, "G_score => %d\n", dna->area[x][y].node.g);
	dprintf(2, "F_score => %d\n", dna->area[x][y].node.f);
	dprintf(2, "----------------------------------------------------\n");
	//
	// dprintf(2, "HOW MANY IN OPEN\n");
}


//on va chercher la meilleur noeud dans les noeud au statut OPEN
int		best_node(t_fil *dna, t_vect *pos)
{
	dprintf(2, "--#Enter Best Node#--\n");
	int y;
	int x;
	int find;
	int score;
	t_vect best;

	y = 0;
	find = 0;
	score = 0;


	while (y < dna->map.h)
	{
		x = 0;
		while (x < dna->map.w)
		{
			// dprintf(2, "State => %d\n", dna->area[x][y].node.state);
			if (dna->area[x][y].node.state == OPEN)
			{
				if (!find || dna->area[x][y].node.f < score)
				{
					best = vect(x, y);
					// dprintf(2, "x=> %d   y=> %d\n", x, y);
					// dprintf(2, "F SCORE => %d\n", dna->area[x][y].node.f);
					score = dna->area[x][y].node.f;
				}
				find = 1;
			}
			//dprintf(2, "FINDUS F_score => %d\n", dna->area[x][y].node.f);
			x++;
		}
		y++;
	}

	// dprintf(2, "BEST F_score => %d\n", score);

	if (find)
	{
		pos->x = best.x;
		pos->y = best.y;
		return (1);
	}
	else
		return (0);
}

void	near_nodes(t_fil *dna, t_node *tmp, t_vect parent)
{
	dprintf(2, "--#Enter Near Node#--\n");
	//si check == 1 on ajoute le node a open list
	// dprintf(2, "State please => %d\n", dna->area[parent.x][parent.y].node.state);
	// dprintf(2, "State please => %d\n", dna->area[parent.x-1][parent.y].node.state);
	// dprintf(2, "State please => %d\n", dna->area[parent.x+1][parent.y].node.state);

	if (check_node(dna, parent, vect(UP)))
	{
		// dprintf(2, "PERSONAL COMPUTER 1\n");
		add_open(dna, parent, vect(UP));
		// dprintf(2, "x> %d  y> %d \n", parent.x + 0, parent.y + (-1));
	}

	if (check_node(dna, parent, vect(DOWN)))
	{
		// dprintf(2, "PERSONAL COMPUTER 2\n");
		add_open(dna, parent, vect(DOWN));
		// dprintf(2, "x> %d  y> %d \n", parent.x + 0, parent.y + 1);
	}
	// dprintf(2, "PINOCCHIO\n");
	if (check_node(dna, parent, vect(LEFT)))
	{
		// dprintf(2, "GEPETTO\n");
		// dprintf(2, "PERSONAL COMPUTER 3\n");
		add_open(dna, parent, vect(LEFT));
		// dprintf(2, "LEFT : x> %d  y> %d \n", parent.x + (-1), parent.y + 0);
	}
	if (check_node(dna, parent, vect(RIGHT)))
	{
		// dprintf(2, "PERSONAL COMPUTER 4\n");
		add_open(dna, parent, vect(RIGHT));
	}

	// if (check_node(dna, parent, vect(UP)))
	// 	dprintf(2, "Ta maman\n");
	// if (check_node(dna, parent, vect(DOWN)))
	// 	dprintf(2, "Ta maman\n");
	// if (check_node(dna, parent, vect(LEFT)))
	// 	dprintf(2, "Ta maman\n");
	// if (check_node(dna, parent, vect(RIGHT)))
	// 	dprintf(2, "Ta maman\n");

}

void	pathfinding(t_fil *dna)
{
	t_node tmp[4];
	t_vect cur;

	dna->from.x = dna->startx;
	dna->from.y = dna->starty;

	// dprintf(2, "dna start x %d\n", dna->startx);
	// dprintf(2, "dna start y %d\n", dna->starty);
	// dna->area[][]
	cur.x = dna->from.x;
	cur.y = dna->from.y;

	dna->area[dna->from.x][dna->from.y].path = 'A';
	dprintf(2, "Start A >  x = %d   y = %d\n", cur.x, cur.y);
	dna->area[dna->goal.x][dna->goal.y].path = 'B';
	dna->area[dna->from.x][dna->from.y].node.state = CLOSED;

	// dprintf(2, "Test goal=> %d  %d\n", dna->goal.x, dna->goal.y);
	//trouver les noeuds proches et les mettre en openlist
	// dprintf(2, "Seigle faulte One\n");
	dprintf(2, "----------------------------NEAR NODE ENTER\n");
	near_nodes(dna, tmp, cur);
	dprintf(2, "----------------------------NEAR NODE EXIT\n");

	//dprintf(2, "KONG => %d\n", tmp[0].state);

	//recalculer tous les noeuds dans open ou garder une liste des nouveaux
	//et faire les updates quand necessaire

	//rendre current le meilleur noeud
	// dprintf(2, "----------------------------BEST NODE ENTER\n");
	// if(best_node(dna, &cur))
	// {
	// 	dprintf(2, "Best Node Find !!! It's x=%d y=%d\n", cur.x, cur.y);
	// 	dprintf(2, "Best score => %d\n", dna->area[cur.x][cur.y].node.f);
	// 	dprintf(2, "Best score h => %d\n", dna->area[cur.x][cur.y].node.h);
	// 	dprintf(2, "Best score g => %d\n", dna->area[cur.x][cur.y].node.g);
	// 	// dprintf(2, "x => %d  y => %d\n", cur.x, cur.y);
	// 	dna->area[cur.x][cur.y].path = '#';
	// 	dna->area[cur.x][cur.y].node.state = CLOSED;
	//
	// }
	// dprintf(2, "----------------------------BEST NODE EXIT\n");

	// dprintf(2, "----------------------------NEAR NODE TWO\n");
	// near_nodes(dna, tmp, cur);

	// if(best_node(dna, &cur))
	// {
	// 	dprintf(2, "Best Node Find !!! It's x=%d y=%d\n", cur.x, cur.y);
	// 	dprintf(2, "Best score => %d\n", dna->area[cur.x][cur.y].node.f);
	// 	dprintf(2, "Best score h => %d\n", dna->area[cur.x][cur.y].node.h);
	// 	dprintf(2, "Best score g => %d\n", dna->area[cur.x][cur.y].node.g);
	// 	// dprintf(2, "x => %d  y => %d\n", cur.x, cur.y);
	// 	dna->area[cur.x][cur.y].path = '#';
	//
	// }
	// dprintf(2, "----------------------------NEAR NODE TWO END\n");

	while (best_node(dna, &cur))
	{
		dprintf(2, "Best node > x%d   y%d\n", cur.x, cur.y);
		dna->area[cur.x][cur.y].path = '#';
		dna->area[cur.x][cur.y].node.state = CLOSED;
		near_nodes(dna, tmp, cur);

		if (cur.x == dna->goal.x && cur.y == dna->goal.y)
		{
			dprintf(2, "---------------------------------------------------------------------------------STOP PATHFINDING\n");
			break;
		}
	}




	// dna->area[cur.x][cur.y].path = 'N';

	debug_path_map(dna);
}
