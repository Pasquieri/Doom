/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_calcul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:40:29 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/03 13:40:48 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	exec_calcul(t_env *env, int d_regard)
{
	env->map_entree = 0;
	env->coef = 400 / (env->x + env->y);
	init_env(env);
	env->d_regard = d_regard;
	affichage_mur(env);
	color_case(env);
	quadrillage(env);
	print_cercle(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_put_image_to_window(env->mlx, env->win, env->img2, 960, 20);
}
