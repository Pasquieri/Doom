/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection_mur_horizontal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:45:43 by cpalmier          #+#    #+#             */
/*   Updated: 2019/03/18 19:07:27 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	init_coord_lim(t_coord *coord, int lim)
{
	coord->x > lim ? coord->x = lim : coord->x;
	coord->y > lim ? coord->y = lim : coord->y;
	coord->x < 0 ? coord->x = 0 : coord->x;
	coord->y < 0 ? coord->y = 0 : coord->y;
}

static void	init_coord(t_env *env, t_coord *coord, int coef, int cas)
{
	int	a;

	a = 0;
	if (cas == 1)
	{
		a = env->perso_x;
		while ((coef == 1) && (a % env->coef) != 0)
			a++;
		while ((coef == -1) && (a % env->coef) != 0)
			a--;
		coord->x = a;
		coord->y = env->perso_y;
	}
	else if (cas == 2)
	{
		a = env->perso_y;
		while ((coef == 1) && (a % env->coef) != 0)
			a++;
		while ((coef == -1) && (a % env->coef) != 0)
			a--;
		coord->x = env->perso_x;
		coord->y = a;
	}
}

int			init_var_hor(t_env *env, double *ya, double *xa, t_coord *coord1)
{
	int	coef;
	t_coord	perso;

	perso.x = env->perso_x;
	perso.y = env->perso_y;

	coef = 1;
	if (env->angle == 0. || env->angle == 180.)
	{
		*ya = 0;
		*xa = env->coef;
		env->angle == 180. ? coef = -1 : coef;
		init_coord(env, coord1, coef, 1);
	}
	else if (env->angle == 90. || env->angle == 270.)
	{
		*ya = env->coef;
		*xa = 0;
		env->angle == 90. ? coef = -1 : coef;
		init_coord(env, coord1, coef, 2);
	}
	else
	{
		*ya = env->coef;
		*xa = env->coef / tan(env->angle * M_PI / 180);
		if (intersection_horizontal(env, coord1) == 1)
			return (1);
	}
	return (0);
}

int			coef_hor(t_env *env, int *coef_x, int *coef_y)
{
	*coef_x = 1;
	*coef_y = 1;
	if (env->angle > 0. && env->angle < 180.)
		*coef_y = -1;
	if (env->angle >= 180. && env->angle < 360.)
		*coef_x = -1;
	return (0);
}

int			verif_hor(t_env *env, t_coord *coord)
{
	int	i;
	int	j;
	int	lim;

	lim = env->x * env->coef;
	if (coord->x > lim || coord->y > lim || coord->x < 0 || coord->y < 0)
	{
		init_coord_lim(coord, lim);
		return (-1);
	}
	i = (int)(coord->x / env->coef);
	j = (int)(coord->y / env->coef);
	if (i < env->x && j < env->x)
	{
		if (env->tab[j][i] >= 0 && env->tab[j][i] <= 6) // verif si c'est pas un mur : 0 = mur 1 = rien // exclure 0 quand new parceur
		{
			coord->nb = env->tab[j][i]; // pour les differents types de murs
			return (1);
		}
		j = ((coord->y) - 1) / env->coef;
		if (env->tab[j][i] >= 0 && env->tab[j][i] <= 6)
		{
			coord->nb = env->tab[j][i];
			return (1);
		}
	}
	return (0);
}
