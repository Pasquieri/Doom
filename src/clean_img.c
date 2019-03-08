/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:35:00 by cpalmier          #+#    #+#             */
/*   Updated: 2019/03/01 15:25:31 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	clean_img(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (200 * 200))
	{
		env->img_str2[x] = (char)0;
		env->img_str2[x + 1] = (char)0;
		env->img_str2[x + 2] = (char)0;
		x = x + 4;
		y++;
	}
	y = 0;
	x = 0;
	while (y < (1200 * 870))
	{
		env->img_str[x] = (char)0;
		env->img_str[x + 1] = (char)0;
		env->img_str[x + 2] = (char)0;
		x = x + 4;
		y++;
	}
}
