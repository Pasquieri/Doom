/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacements_extra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:41:52 by cpalmier          #+#    #+#             */
/*   Updated: 2019/03/19 17:48:08 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"
#include <stdio.h>
static int	check_wall(double xa, double ya, t_env *env)
{
	double	x;
	double	y;

	x = env->perso_x + xa;// round(xa);
	y = env->perso_y + ya;//round(ya);
	if (env->tab[(int)y / env->coef][(int)x / env->coef] >= 7
			&& env->tab[((int)y + 1) / env->coef][(int)x / env->coef] >= 7
			&& env->tab[((int)y - 1) / env->coef][(int)x / env->coef] >= 7
			&& env->tab[(int)y / env->coef][((int)x + 1) / env->coef] >= 7
			&& env->tab[(int)y / env->coef][((int)x - 1) / env->coef] >= 7)
		return (0);
	else
		return (1);
}

static double	init_angle(double d_regard)
{
	double	angle;

	angle = 0;
	if (d_regard >= 0 && d_regard < 90)
		angle = d_regard;
	else if (d_regard >= 90 && d_regard < 180)
		angle = 180 - d_regard;
	else if (d_regard >= 180 && d_regard < 270)
		angle = d_regard - 180;
	else if (d_regard >= 270 && d_regard <= 360)
		angle = 360 - d_regard;
	return (angle);
}

static void	init_coef(double d_regard, double *coef_x, double *coef_y)
{
	if (d_regard >= 0 && d_regard < 90)
	{
		*coef_x = 1.;
		*coef_y = -1.;
	}
	else if (d_regard >= 90 && d_regard < 180)
	{
		*coef_x = -1.;
		*coef_y = -1.;
	}
	else if (d_regard >= 180 && d_regard < 270)
	{
		*coef_x = -1.;
		*coef_y = 1.;
	}
	else if (d_regard >= 270 && d_regard <= 360)
	{
		*coef_x = 1.;
		*coef_y = 1.;
	}
}

void		depla_vertical(t_env *env, int key)
{
	double	xa;
	double	ya;
	double	coef_x;
	double	coef_y;
	double	angle;

	if (key == 1)
		angle = env->d_regard - 180;
	else
		angle = env->d_regard;
	if (angle < 0)
		angle = angle + 360;
	else if (angle > 360)
		angle = angle - 360;
	init_coef(angle, &coef_x, &coef_y);
	xa = fabs(cos(angle * M_PI / 180) * env->vitesse);
	ya = fabs(sin(angle * M_PI / 180) * env->vitesse);
	xa = xa * coef_x;
	ya = ya * coef_y;
	//printf("deplacement: %f - %f\n", xa, ya);

	if (check_wall(xa, 0, env) == 0)
	{
		env->perso_x = env->perso_x + xa;//round(xa);
	}
	if (check_wall(0, ya, env) == 0)
	{
		env->perso_y = env->perso_y + ya;//round(ya);
	}
}

void		depla_horizontal(t_env *env, int key)
{
	double	xa;
	double	ya;
	double	coef_x;
	double	coef_y;
	double	angle;

	if (key == 0)
		angle = env->d_regard + 90;
	else
		angle = env->d_regard - 90;
	if (angle < 0)
		angle = angle + 360;
	else if (angle > 360)
		angle = angle - 360;
	init_coef(angle, &coef_x, &coef_y);
	angle = init_angle(angle);
	xa = fabs(cos(angle * M_PI / 180) * env->vitesse);
	ya = fabs(sin(angle * M_PI / 180) * env->vitesse);
	xa = xa * coef_x;
	ya = ya * coef_y;
	if (check_wall(xa, 0, env) == 0)
	{
		env->perso_x = env->perso_x + xa;//round(xa);
	}
	if (check_wall(0, ya, env) == 0)
	{
		env->perso_y = env->perso_y + ya;//round(ya);
	}
}