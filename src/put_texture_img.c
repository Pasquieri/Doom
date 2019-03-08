/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:49:23 by cpalmier          #+#    #+#             */
/*   Updated: 2019/02/28 21:36:15 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	put_texture_img(t_env *env, double h_percue, int y, t_text *texture)
{
	float	pourcent_x;
	float	pourcent_y;
	int		i;
	int		j;
	int		tmp;

	if (env->orientation == 1)
		tmp = ((int)(env->coord_mur.x * 100000) % (env->coef * 100000));
	else
		tmp = ((int)(env->coord_mur.y * 100000) % (env->coef * 100000));
	pourcent_x = ((float)tmp / 100000.) * 100 / env->coef;
	if (y > (env->h_regard - (h_percue / 2)))
		pourcent_y = (y - (env->h_regard - (h_percue / 2.))) * 100. / h_percue;
	else
		pourcent_y = y * 100. / h_percue;
	i = 4 * env->img_x + y * env->s_l;
	j = 4 * (int)(texture->width * pourcent_x / 100)
		+ (int)(texture->height * pourcent_y / 100) * texture->s_l;
	env->img_str[i] = texture->img_str[j];
	env->img_str[i + 1] = texture->img_str[j + 1];
	env->img_str[i + 2] = texture->img_str[j + 2];
}
