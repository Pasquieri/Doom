/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pxl_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:51:35 by cpalmier          #+#    #+#             */
/*   Updated: 2019/02/28 21:36:50 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static void	win_img(t_env *env, int x, int y, int color)
{
	int	i;

	i = 4 * x + y * env->s_l;
	if (color == 5)
	{
		env->img_str[i] = (char)130;
		env->img_str[i + 1] = (char)227;
		env->img_str[i + 2] = (char)130;
	}
	else if (color == 6)
	{
		env->img_str[i] = (char)240;
		env->img_str[i + 1] = (char)130;
		env->img_str[i + 2] = (char)44;
	}
	else if (color == 7)
	{
		env->img_str[i] = (char)93;
		env->img_str[i + 1] = (char)145;
		env->img_str[i + 2] = (char)190;
	}
}

static void	map_img(t_env *env, int x, int y, int color)
{
	int	i;

	i = 4 * x + y * env->s_l2;
	if (color == 0)
	{
		env->img_str2[i] = (char)230;
		env->img_str2[i + 1] = (char)230;
		env->img_str2[i + 2] = (char)230;
	}
	else if (color == 1)
	{
		env->img_str2[i] = (char)113;
		env->img_str2[i + 1] = (char)170;
		env->img_str2[i + 2] = (char)10;
	}
	else if (color == 3)
	{
		env->img_str2[i] = (char)159;
		env->img_str2[i + 1] = (char)161;
		env->img_str2[i + 2] = (char)255;
	}
}

void		put_pxl_img(t_env *env, int x, int y, int color)
{
	if (color < 5)
		map_img(env, x, y, color);
	else
		win_img(env, x, y, color);
}
