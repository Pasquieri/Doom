/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_mur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:27:02 by cpalmier          #+#    #+#             */
/*   Updated: 2019/03/18 18:53:38 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"
#include <stdio.h>

static int		affichage_ciel(double h_percue, t_env *env, int x, float y)
{
	float	lim;
	float	pourcent_x;
	float	pourcent_y;
	int		i;
	int		j;

	y = -1;
	lim = (env->h_regard - (h_percue / 2));
	pourcent_x = (100. * x) / env->nb_colonne;
	while (++y < lim && y < 870.)
	{
		pourcent_y = (100. * y) / (870.);
		i = 4 * x + y * env->m[0].s_l;
		j = 4 * (int)(env->text[22].width * pourcent_x / 100)
			+ (int)(env->text[22].height * (pourcent_y + (100 - (env->h_regard
								* 100 / 870.))) / 100) * env->text[22].s_l;
		env->m[0].img_str[i] = env->text[22].img_str[j];
		env->m[0].img_str[i + 1] = env->text[22].img_str[j + 1];
		env->m[0].img_str[i + 2] = env->text[22].img_str[j + 2];
		//env->m[0].img_str[i] = luminosite(env->text[22].img_str[j], env->lum);
		//env->m[0].img_str[i + 1] = luminosite(env->text[22].img_str[j + 1], env->lum);
		//env->m[0].img_str[i + 2] = luminosite(env->text[22].img_str[j + 2], env->lum);
	}
	return (y - 1);
}

/*static void		affichage_sol(t_env *env, int x, int y)
{
	int	i;

	i = 4 * x + y * env->m[0].s_l;
	env->m[0].img_str[i] = luminosite(env->rgb[7].b, env->lum);
	env->m[0].img_str[i + 1] = luminosite(env->rgb[7].g, env->lum);
	env->m[0].img_str[i + 2] = luminosite(env->rgb[7].r, env->lum);
	env->m[0].img_str[i + 3] = (char)env->rgb[7].a;
}*/


static void		affichage(double h_percue, t_env *env, int x)
{
	float	y;
	float	lim;

	y = 0;
	y = affichage_ciel(h_percue, env, x, y);
	//	lim = (env->h_regard + (h_percue / 2));
	lim = env->lim_sol;
	while (++y < lim && y < 870.) // affichage_mur
	//	put_texture_img(env, h_percue, y, &env->text[env->wall_nb + 1]);
		put_texture_img(env, h_percue, y, &env->text[1]);
                        // +1 car 0 = mur or text[0] = menu
	y--;
	while (++y < 870.)
	//	affichage_sol(env, x, y);
		put_pxl_img(env, x, y, 7);
}

static double	verif_angle(double angle)
{
	if (angle < 0.)
	{
		while (angle < 0.)
			angle = angle + 360.;
	}
	else if (angle > 360.)
	{
		while (angle > 360.)
			angle = angle - 360.;
	}
	if (angle == 360.)
		angle = 0.;
	return (angle);
}

void			affichage_mur(t_env *env)
{
	double	a;
	double	dist;
	double	h_percue;
	int		x;

	a = env->d_regard + 30;
	a = verif_angle(a);
	x = 0;
	while (x < (env->nb_colonne))
	{
		env->angle = a;
		env->angle = verif_angle(env->angle);
		dist = detection_mur(env);
		dist = dist * cos((a - env->d_regard) * M_PI / 180);
		h_percue = env->d_ecran * (env->h_mur / dist);
		env->lum = dist * 255 / env->lum_int;
		env->h_ref = env->d_ecran * (env->coef / dist);
		env->lim_sol = env->h_regard + (env->h_ref / 2);
		env->img_x = x;
		affichage(h_percue, env, x);
		a -= (60. / (env->nb_colonne));
		x++;
	}
}
