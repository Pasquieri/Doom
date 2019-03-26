/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig_press.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:45:50 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/18 17:58:09 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

static void	key_menu_extra(t_env *env)
{
	if (env->menu_select == 3)
	{
		if (re_pars("./map/map.2", env) == -1)
			env->menu = 1;
		else
			exec_calcul(env, 180, 1);
	}
	if (env->menu_select == 4)
	{
		if (re_pars("./map/map.3", env) == -1)
			env->menu = 1;
		else
			exec_calcul(env, 225, 1);
	}
	if (env->menu_select == 5)
	{
		if (re_pars("./map/map.4", env) == -1)
			env->menu = 1;
		else
			exec_calcul(env, 0, 1);
	}
	if (env->menu == 1)
		open_menu(env);
	if (env->menu_select == 6)
		exit(0);
}

void		key_invalid_menu(t_env *env)
{
	env->menu = 0;
	if (env->menu_select <= 2)
	{
		if (re_pars("./map/map.1", env) == -1)
			env->menu = 1;
		else
			exec_calcul(env, 0, 1);
	}
	key_menu_extra(env);
}

void		key_valid_menu(t_env *env)
{
	env->menu = 0;
	if (env->menu_select == 2)
	{
		if (re_pars("./map/map.1", env) == -1)
			env->menu = 1;
		else
			exec_calcul(env, 0, 1);
	}
	key_menu_extra(env);
}

int			trig_press(t_env *env)
{
	int	i;

	i = 0;
	if ((env->key[0] || env->key[1] || env->key[2] || env->key[13])
			&& !env->menu)
		deplacements(env);
	if ((env->key[69] || env->key[78] || env->key[123] || env->key[124]
				|| env->key[125] || env->key[126]) && !env->menu)
		rotation_regard(env);
	if (env->key[27] || env->key[24])
	{
		if (env->key[27])
			env->lum_int -= 3;
		if (env->key[24])
			env->lum_int += 3;
		env->lum_int < 1 ? env->lum_int = 1 : env->lum_int;
		env->lum_int > 500 ? env->lum_int = 500 : env->lum_int;
	}
	if (!env->menu)
		exec_calcul(env, 0, 0);
	return (0);
}
