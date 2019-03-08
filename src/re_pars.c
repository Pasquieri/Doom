/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:42:37 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/03 18:32:39 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/wolf3d.h"

int	re_pars(char *str, t_env *env)
{
	int	fd;
	int	j;

	env->map_entree = -1;
	fd = -1;
	env->detail = 0;
	fd = check_open_map(str, fd, env);
	if (fd == -1)
		return (-1);
	j = 0;
	while (j < env->y)
	{
		free(env->tab[j]);
		j++;
	}
	free(env->tab);
	if (check_file(fd, env) == -1)
		return (-1);
	env->map_entree = 0;
	return (0);
}
