/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 01:01:29 by lchety            #+#    #+#             */
/*   Updated: 2017/04/06 01:29:22 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void 	create_score_map()
{
	int x;
	int y;

	x = 0;
	y = 0;

	while
	{
		while
		{
			score_map[x][y] = '0';

		}

	}


}

void	score_map()
{
	int x;
	int y;
	//pas oublier de free
	create_score_map();

	while (x)
	{
		while(y)
		{
			if map[][] == dna->ennemy_sign
				map_score[x][y] = 0;


		}
 	}

	while (x)
	{
		while(y)
		{
			if map_score[x + 1][y] > map_score[x][y]
				map_score[x + 1][y] = map_score[x][y] - 1;
			if map_score[x - 1][y] > map_score[x][y]
				map_score[x + 1][y] = map_score[x][y] - 1;
			if map_score[x][y + 1] > map_score[x][y]
				map_score[x + 1][y] = map_score[x][y] - 1;
			if map_score[x][y - 1] > map_score[x][y]
				map_score[x + 1][y] = map_score[x][y] - 1;
		}
	}
}

int		pose_piece(v2d origin)
{
	int error;
	int contact;
	int score

	while (y < dna->piece.h)
	{
		while (x < dna->piece.w)
		{
			if (map[origin.x + x][origin.y + y] == ennemy_sign)
				error = 1;

			if (map[origin.x + x][origin.y + y] == player_sign)
				contact++;

				//map limits
			if (origin.x + x > map.w || origin.y + y > map.w )
				error = 1

			score += score_map[x][y];


		}

	}
	if score > dna->bestmove->score
		dna->best.score = score;
		dna->best.x = origin.x;
		dna->best.x = origin.y;

	if(contact == 1 && !error)
		return (1);
	return(0);

}

void	piece_tester()
{

	while
	{
		while()
		{
			pose_piece();

		}

	}


}
