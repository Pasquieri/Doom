/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pxl_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:51:35 by cpalmier          #+#    #+#             */
/*   Updated: 2019/03/14 15:40:54 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	init_rgb(t_env *env)
{
	env->rgb[0] = (t_rgb){230, 230, 230, 0}; // blanc
	env->rgb[1] = (t_rgb){113, 170, 10, 100}; // vert
	env->rgb[3] = (t_rgb){159, 161, 255, 0}; // rose
	env->rgb[5] = (t_rgb){130, 227, 130, 0}; // vert
	env->rgb[6] = (t_rgb){240, 130, 44, 0}; // bleu
	env->rgb[7] = (t_rgb){93, 145, 190, 0}; // marron
}

void		put_pxl_img(t_env *env, int x, int y, int color)
{
	int	i;
	int	k;

	if (color < 5)
		k = 1;
	else
		k = 0;
	i = 4 * x + y * env->m[k].s_l;
	env->m[k].img_str[i] = (char)env->rgb[color].b;
	env->m[k].img_str[i + 1] = (char)env->rgb[color].g;
	env->m[k].img_str[i + 2] = (char)env->rgb[color].r;
	env->m[k].img_str[i + 3] = (char)env->rgb[color].a;
}
