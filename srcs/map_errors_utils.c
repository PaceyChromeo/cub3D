/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrifa <hkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:40:56 by hkrifa            #+#    #+#             */
/*   Updated: 2021/11/08 15:37:19 by hkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int pos_1(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			break ;
		i++;
	}
	return (i);
}

static int	pos_2(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if (str[i] == '1')
			break ;	
		i--;
	}
	return (i);
}

static int valid_walls(char *str, int pos1, int pos2)
{
	(void)pos2;
	if (pos1 != 0)
	{
		if (str[pos1 - 1] != ' ')
			return (1);
	}
	
	return (0);
}

int check_valid_walls(t_map *map)
{
	int i;
	int pos1;
	int pos2;
	
	i = 1;
	while (i < map->count_line - 1)
	{
		pos1 = pos_1(map->tab[i]);
		pos2 = pos_2(map->tab[i]);
		if (valid_walls(map->tab[i], pos1, pos2))
			return (1);	
		i++;
	}
	return (0);
}
