/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:04:19 by lchety            #+#    #+#             */
/*   Updated: 2017/04/20 14:51:50 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_vect		vect(int x, int y)
{
	t_vect ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}
