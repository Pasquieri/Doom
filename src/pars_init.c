/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:41:37 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/01 16:41:49 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		pars_init(int argc, char **argv, t_env *env)
{
	int		fd;

	fd = -1;
	env->detail = 0;
	if (argc != 2)
	{
		if (argc == 3)
		{
			if (ft_atoi(argv[2]) > 0)
				env->detail = 1;
		}
		else
			return (error_message(1, env));
	}
	fd = check_open_map(argv[1], fd, env);
	if (fd == -1)
		return (-1);
	if (check_file(fd, env) == -1)
		return (-1);
	env->map_entree = 0;
	return (0);
}
