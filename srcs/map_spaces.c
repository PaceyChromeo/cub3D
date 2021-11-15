/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:03:25 by hkrifa            #+#    #+#             */
/*   Updated: 2021/11/15 11:25:00 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	check_in(t_map *map, int i, int j)
{
	if (i > 0 && i < map->count_line - 1 && j > 0 && j < map->max_len - 1)
	{
		if ((map->tab[i + 1][j] != '1' && map->tab[i + 1][j] != ' ')
			|| (map->tab[i - 1][j] != '1' && map->tab[i - 1][j] != ' '))
			return (1);
		if ((map->tab[i][j + 1] != '1' && map->tab[i][j + 1] != ' ')
			|| (map->tab[i][j - 1] != '1' && map->tab[i][j - 1] != ' '))
			return (1);
	}
	return (0);
}

static int	check_around_mapnorm(t_map *map, int i, int j)
{
	if (i > 0 && i < map->count_line - 1 && j == 0)
	{
		if (map->tab[i][j + 1] != ' ' && map->tab[i][j + 1] != '1')
			return (1);
		if (map->tab[i + 1][j] != ' ' && map->tab[i + 1][j] != '1')
			return (1);
		if (map->tab[i - 1][j] != ' ' && map->tab[i - 1][j] != '1')
			return (1);
	}
	return (0);
}

static int	check_around_map(t_map *map, int i, int j)
{
	if (i == 0)
	{
		if (map->tab[i + 1][j] != ' ' && map->tab[i + 1][j] != '1')
			return (1);
	}
	if (i == map->count_line - 1)
	{
		if (map->tab[i - 1][j] != ' ' && map->tab[i - 1][j] != '1')
			return (1);
	}
	if (i > 0 && i < map->count_line - 1 && j == map->max_len - 1)
	{
		if (map->tab[i + 1][j] != ' ' && map->tab[i + 1][j] != '1')
			return (1);
		if (map->tab[i - 1][j] != ' ' && map->tab[i - 1][j] != '1')
			return (1);
		if (map->tab[i][j - 1] != ' ' && map->tab[i][j - 1] != '1')
			return (1);
	}
	return (0);
}

int	check_valid_spaces(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (map->tab[i][j] == 32)
			{
				if (check_around_map(map, i, j)
					|| check_around_mapnorm(map, i, j)
					|| check_in(map, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
