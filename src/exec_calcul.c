/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_calcul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:40:29 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/14 16:43:17 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void		clean_img(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (200 * 200))
	{
		env->m[1].img_str[x] = (char)0;
		env->m[1].img_str[x + 1] = (char)0;
		env->m[1].img_str[x + 2] = (char)0;
		env->m[1].img_str[x + 3] = (char)0;
		x = x + 4;
		y++;
	}
	y = 0;
	x = 0;
	while (y < (1200 * 870))
	{
		env->m[0].img_str[x] = (char)0;
		env->m[0].img_str[x + 1] = (char)0;
		env->m[0].img_str[x + 2] = (char)0;
		env->m[0].img_str[x + 3] = (char)0;
		x = x + 4;
		y++;
	}
}

static void	init_var(t_env *env, int d_regard)
{
	env->map_entree = 0;
	env->coef = 400 / (env->x + env->y);
	init_env(env);
	env->d_regard = d_regard;
}

void	exec_calcul(t_env *env, int d_regard, int init)
{
	if (init == 1)
		init_var(env, d_regard);
	clean_img(env);
	affichage_mur(env);
	color_case(env);
	quadrillage(env);
	print_cercle(env);
	mlx_put_image_to_window(env->mlx, env->win, env->m[0].img, 0, 0);
	print_sprite(env);
	if (env->map_on == 1)
		mlx_put_image_to_window(env->mlx, env->win, env->m[1].img, 960, 20);
}
