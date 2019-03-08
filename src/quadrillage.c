/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrillage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:53:44 by cpalmier          #+#    #+#             */
/*   Updated: 2019/02/28 21:31:52 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static void	init_coord(t_coord *coord1, t_coord *coord3, t_env *env)
{
	coord3->x = coord1->x;
	coord3->y = coord1->y - env->coef;
}

void		quadrillage(t_env *env)
{
	int		i;
	int		j;
	t_coord	coord1;
	t_coord	coord2;
	t_coord	coord3;

	j = -1;
	while (++j <= env->y)
	{
		coord1.y = j * env->coef;
		coord2.y = j * env->coef;
		i = -1;
		while (++i <= env->x)
		{
			coord1.x = i * env->coef;
			coord2.x = (i + 1) * env->coef;
			if ((i + 1) <= env->x)
				ft_trace_seg(env, coord1, coord2);
			if (j > 0)
			{
				init_coord(&coord1, &coord3, env);
				ft_trace_seg(env, coord1, coord3);
			}
		}
	}
}
