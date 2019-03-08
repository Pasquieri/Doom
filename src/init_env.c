/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:48:45 by cpalmier          #+#    #+#             */
/*   Updated: 2019/03/03 11:58:06 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	init_env(t_env *env)
{
	env->d_regard = 0;
	env->d_regard = env->d_regard % 360;
	if (env->d_regard < 0)
		env->d_regard = env->d_regard + 360;
	env->x_init = env->perso_x;
	env->y_init = env->perso_y;
	env->perso_x = (env->x_init + 1) * env->coef - env->coef / 2;
	env->perso_y = (env->y_init + 1) * env->coef - env->coef / 2;
	env->nb_colonne = 1200;
	env->d_ecran = (env->nb_colonne / 2) / tan(30 * M_PI / 180);
	env->h_mur = env->coef;
	env->h_regard = 870 / 2;
	env->map_on = 1;
	env->lim = env->x * env->coef - (env->coef / 2);
}
