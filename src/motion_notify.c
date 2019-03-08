/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_notify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:43:26 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/03 13:44:02 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		motion_notify(int x, int y, t_env *env)
{
	if (env->menu == 1)
		return (0);
	if (x > 1200 || x < 0 || y > 870 || y < 0)
		return (0);
	if (x > 650)
		env->d_regard -= 1;
	else if (x < 550)
		env->d_regard += 1;
	if (y < 250 && (env->h_regard < (870 / 2 + 200)))
		env->h_regard += 2;
	else if (y > 620 && (env->h_regard > (870 / 2 - 200)))
		env->h_regard -= 2;
	env->d_regard = env->d_regard % 360;
	if (env->d_regard < 0)
		env->d_regard = env->d_regard + 360;
	clean_img(env);
	affichage_mur(env);
	color_case(env);
	quadrillage(env);
	print_cercle(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	if (env->map_on == 1)
		mlx_put_image_to_window(env->mlx, env->win, env->img2, 960, 20);
	return (0);
}
