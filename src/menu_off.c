/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_off.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:42:45 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/03 15:13:00 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	menu_off(t_env *env)
{
	clean_img(env);
	affichage_mur(env);
	color_case(env);
	quadrillage(env);
	print_cercle(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	if (env->x <= 50)
	{
		if (env->key[46] && env->map_on == 1)
			env->map_on = 0;
		else if (env->key[46] && env->map_on == 0)
			env->map_on = 1;
		if (env->map_on == 1)
			mlx_put_image_to_window(env->mlx, env->win, env->img2, 960, 20);
	}
	else
		env->map_on = 0;
}
