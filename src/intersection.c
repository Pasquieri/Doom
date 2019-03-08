/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:49:16 by cpalmier          #+#    #+#             */
/*   Updated: 2019/02/25 12:01:56 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static int	verif_horizontal(float y2, t_env *env)
{
	int	j;

	j = (y2) / env->coef;
	if (j != (env->perso_y / env->coef))
		return (1);
	j = (y2 - 1) / env->coef;
	if (j != (env->perso_y / env->coef))
		return (1);
	else
		return (0);
}

int			intersection_horizontal(t_env *env, t_coord *cd)
{
	int		ya;
	int		coef_y;
	int		coef_x;

	ya = 0;
	cd->x = env->perso_x;
	cd->y = env->perso_y;
	coef_y = 1;
	coef_x = 1;
	if (env->angle > 0. && env->angle < 180.)
		coef_y = -1;
	if (env->angle > 180. && env->angle < 360.)
		coef_x = -1;
	while (ya < env->coef && (cd->x < env->lim && cd->x > 0.)
			&& (cd->y < env->lim && cd->y > 0.))
	{
		cd->y = env->perso_y + (ya * coef_y);
		cd->x = env->perso_x + ((ya * coef_x) / tan(env->angle * M_PI / 180));
		if (verif_horizontal(cd->y, env) == 1)
			return (0);
		ya++;
	}
	return (1);
}

static int	verif_vertical(float x2, t_env *env)
{
	int	i;

	i = (x2) / env->coef;
	if (i != (env->perso_x / env->coef))
		return (1);
	i = (x2 - 1) / env->coef;
	if (i != (env->perso_x / env->coef))
		return (1);
	else
		return (0);
}

int			intersection_vertical(t_env *env, t_coord *cd)
{
	int		xa;
	int		coef_x;
	int		coef_y;

	xa = 0;
	cd->x = env->perso_x;
	cd->y = env->perso_y;
	coef_x = 1;
	coef_y = 1;
	if (env->angle > 90. && env->angle < 270.)
		coef_x = -1;
	if (!(env->angle > 90. && env->angle < 270.))
		coef_y = -1;
	while (xa < env->coef && (cd->x < env->lim && cd->x > 0.)
			&& (cd->y < env->lim && cd->y > 0.))
	{
		cd->x = env->perso_x + (xa * coef_x);
		cd->y = env->perso_y + ((xa * coef_y) * tan(env->angle * M_PI / 180));
		if (verif_vertical(cd->x, env) == 1)
			return (0);
		xa++;
	}
	return (1);
}
