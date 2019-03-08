/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 20:15:32 by cpalmier          #+#    #+#             */
/*   Updated: 2019/03/01 20:18:51 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	init_texture(t_env *env)
{
	env->texture1.img = mlx_xpm_file_to_image(env->mlx,
		"textures/marbre_blanc.XPM", &env->texture1.width,
		&env->texture1.height);
	env->texture1.img_str = mlx_get_data_addr(env->texture1.img,
		&env->texture1.bpp, &env->texture1.s_l, &env->texture1.end);
	env->texture2.img = mlx_xpm_file_to_image(env->mlx,
		"textures/plante.XPM", &env->texture2.width, &env->texture2.height);
	env->texture2.img_str = mlx_get_data_addr(env->texture2.img,
		&env->texture2.bpp, &env->texture2.s_l, &env->texture2.end);
	env->texture3.img = mlx_xpm_file_to_image(env->mlx,
		"textures/planche_bois.XPM",
		&env->texture3.width, &env->texture3.height);
	env->texture3.img_str = mlx_get_data_addr(env->texture3.img,
		&env->texture3.bpp, &env->texture3.s_l, &env->texture3.end);
	env->texture4.img = mlx_xpm_file_to_image(env->mlx,
		"textures/carrelage_noir.XPM",
		&env->texture4.width, &env->texture4.height);
	env->texture4.img_str = mlx_get_data_addr(env->texture4.img,
		&env->texture4.bpp, &env->texture4.s_l, &env->texture4.end);
	env->texture5.img = mlx_xpm_file_to_image(env->mlx,
		"textures/ciel.XPM", &env->texture5.width, &env->texture5.height);
	env->texture5.img_str = mlx_get_data_addr(env->texture5.img,
		&env->texture5.bpp, &env->texture5.s_l, &env->texture5.end);
}
