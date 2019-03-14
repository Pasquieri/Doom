/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:30:27 by cpalmier          #+#    #+#             */
/*   Updated: 2019/03/13 18:51:22 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static void	init_sprite(t_env *env)
{
	env->sp[0].img = mlx_xpm_file_to_image(env->mlx,
			"textures/Column_sprite.XPM", &env->sp[0].width,
			&env->sp[0].height);
	env->sp[0].img_str = mlx_get_data_addr(env->sp[0].img, &env->sp[0].bpp,
			&env->sp[0].s_l, &env->sp[0].end);
}

static void	put_sprite(int i, int j, t_env *env)
{
	int	x;
	int	y;

	x = i * env->coef + 1;
	y = j * env->coef + 1;

	x = 1200 * x / 200;
	y = 870 * y / 200;
	mlx_put_image_to_window(env->mlx, env->win, env->sp[0].img, x, y);
}

void	print_sprite(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	init_sprite(env);
	while (j < env->y)
	{
		i = 0;
		while (i < env->x)
		{
			if (env->tab[j][i] == 2)
				put_sprite(i, j, env);
			i++;
		}
		j++;
	}
}
