/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cercle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:33:03 by cpalmier          #+#    #+#             */
/*   Updated: 2019/02/21 18:07:41 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void		print_cercle(t_env *env)
{
	t_cercle	param_cercle;

	param_cercle.coord.x = env->perso_x;
	param_cercle.coord.y = env->perso_y;
	param_cercle.rayon = 5;
	param_cercle.color = 3;
	while (param_cercle.rayon >= 0)
	{
		cercle(env, param_cercle);
		param_cercle.rayon--;
	}
}

static void	verif_mur(t_env *env, int x, int y, int color)
{
	int	i;

	i = 4 * x + y * env->s_l2;
	put_pxl_img(env, x, y, color);
}

void		cercle(t_env *env, t_cercle param)
{
	int x;
	int y;
	int m;

	x = 0;
	y = param.rayon;
	m = 5 - 4 * param.rayon;
	while (x <= y)
	{
		verif_mur(env, x + param.coord.x, -y + param.coord.y, param.color);
		verif_mur(env, y + param.coord.x, -x + param.coord.y, param.color);
		verif_mur(env, y + param.coord.x, x + param.coord.y, param.color);
		verif_mur(env, x + param.coord.x, y + param.coord.y, param.color);
		verif_mur(env, -x + param.coord.x, y + param.coord.y, param.color);
		verif_mur(env, -y + param.coord.x, x + param.coord.y, param.color);
		verif_mur(env, -y + param.coord.x, -x + param.coord.y, param.color);
		verif_mur(env, -x + param.coord.x, -y + param.coord.y, param.color);
		if (m > 0)
		{
			y--;
			m = m - 8 * y;
		}
		x++;
		m = m + 8 * x + 4;
	}
}
