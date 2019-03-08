/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:49:29 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/03 18:32:03 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		verif_char(char *str, t_env *env)
{
	int		x;
	char	nombre[3];

	nombre[2] = '\0';
	x = -1;
	while (str[++x])
	{
		if (str[x + 1] != '\0')
		{
			nombre[0] = str[x];
			nombre[1] = str[x + 1];
			if (str[x] != ' ' && str[x + 1] != ' ')
			{
				free(str);
				return (error_message(7, env));
			}
		}
		if ((str[x] != '\0') && (str[x] != ' ') && ((str[x] >= 48)
					&& (str[x] <= 39) && (str[x] != '\n') && (str[x] != '\t')))
		{
			free(str);
			return (error_message(7, env));
		}
	}
	return (x);
}
