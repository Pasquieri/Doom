/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:44:47 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/03 13:45:44 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		win_init(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		return (-1);
	env->win = mlx_new_window(env->mlx, 1200, 870, "Wolf3D");
	env->imgmenu = mlx_new_image(env->mlx, 1200, 870);
	env->img = mlx_new_image(env->mlx, 1200, 870);
	env->img_str = mlx_get_data_addr(env->img,
			&env->bpp, &env->s_l, &env->end);
	env->img2 = mlx_new_image(env->mlx, 200, 200);
	env->img_str2 = mlx_get_data_addr(env->img2, &env->bpp2,
		&env->s_l2, &env->end2);
	init_texture(env);
	env->text_menu.img = mlx_xpm_file_to_image(env->mlx,
		"textures/labyrinthe.XPM", &env->text_menu.width,
		&env->text_menu.height);
	env->text_menu.img_str = mlx_get_data_addr(env->text_menu.img,
		&env->text_menu.bpp, &env->text_menu.s_l, &env->text_menu.end);
	return (0);
}
