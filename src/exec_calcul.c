/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_calcul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:40:29 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/19 17:09:29 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void		clean_img(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (200 * 200))
	{
		env->m[1].img_str[x] = (char)0;
		env->m[1].img_str[x + 1] = (char)0;
		env->m[1].img_str[x + 2] = (char)0;
		env->m[1].img_str[x + 3] = (char)0;
		x = x + 4;
		y++;
	}
	y = 0;
	x = 0;
	while (y < (1200 * 870))
	{
		env->m[0].img_str[x] = (char)0;
		env->m[0].img_str[x + 1] = (char)0;
		env->m[0].img_str[x + 2] = (char)0;
		env->m[0].img_str[x + 3] = (char)0;
		x = x + 4;
		y++;
	}
}

/*static void	init_sprite(t_env *env)
{
	env->sp[0].img = mlx_xpm_file_to_image(env->mlx,
			"textures/12-column.XPM", &env->sp[0].width, &env->sp[0].height);
	env->sp[0].img_str = mlx_get_data_addr(env->sp[0].img, &env->sp[0].bpp,
			&env->sp[0].s_l, &env->sp[0].end);
	env->sp[1].img = mlx_xpm_file_to_image(env->mlx, "textures/gun.XPM",
			&env->sp[1].width, &env->sp[1].height);
	env->sp[1].img_str = mlx_get_data_addr(env->sp[1].img, &env->sp[1].bpp,
			&env->sp[1].s_l, &env->sp[1].end);
//	printf("arme : width : %d, height : %d\n", env->sp[1].width, env->sp[1].height);
}*/

static void	init_var(t_env *env, int d_regard)
{
	env->map_entree = 0;
	env->coef = 400 / (env->x + env->y);
	init_env(env);
	env->d_regard = d_regard;

	init_sprite(env);
//	env->inv.gun = 1; // faire quand obj ramasse
	env->inv.lim_gun[0] = 0;   // pour les 4 imgs dans la sprite sheet :
	env->inv.lim_gun[1] = 150; // separation (x) entre chaque 
	env->inv.lim_gun[2] = 365; // theoriquement ... a voir si besoin de le 
	env->inv.lim_gun[3] = 575; // pour chaque sprite sheet ...
	env->inv.lim_gun[4] = 732;
}

void	exec_calcul(t_env *env, int d_regard, int init)
{
	if (init == 1)
		init_var(env, d_regard);
	clean_img(env);
	affichage_mur(env);
	color_case(env);
	quadrillage(env); // enlever pour plus de lisibilite sur la mini map
	print_cercle(env);
	//	printf("sprite : {%c,%c,%c,%c}\n", env->sp[1].img_str[400],env->sp[1].img_str[401],env->sp[1].img_str[402],env->sp[1].img_str[403]);
	if (env->inv.gun == 1)
		print_gun(env, 2);
	mlx_put_image_to_window(env->mlx, env->win, env->m[0].img, 0, 0);
	mlx_put_image_to_window(env->mlx, env->win, env->m[1].img, 960, 20);
}
