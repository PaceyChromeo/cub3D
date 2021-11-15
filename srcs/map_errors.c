/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:25:57 by hkrifa            #+#    #+#             */
/*   Updated: 2021/11/15 09:52:33 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int check_valid_spawn(t_map *map)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (map->tab[i])
	{
		j = 0;
		while(map->tab[i][j])
		{
			if (map->tab[i][j] == 'N' || map->tab[i][j] == 'S' 
				|| map->tab[i][j] == 'E' || map->tab[i][j] == 'W')
			{
				map->pl_x = i;
				map->pl_y = j;
				map->pl_view = map->tab[i][j];
				count++;
			}
			j++;
		}
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

static int check_valid_char(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (map->tab[i][j] != ' ' && map->tab[i][j] != '1' && map->tab[i][j] != '0' 
				&& map->tab[i][j] != 'N' && map->tab[i][j] != 'S' 
				&& map->tab[i][j] != 'E' && map->tab[i][j] != 'W')
				return(1);
			j++;	
		}
		i++;
	}
	return (0);
}

static int	check_valid_top(t_map *map)
{
	int j;

	j = 0;
	while (map->tab[0][j])
	{
		if (map->tab[0][j] != '1' && map->tab[0][j] != ' ')
			return(1);
		j++;
	}
	return (0);
}

static int check_valid_bottom(t_map *map)
{
	int i;
	int j;

	j = 0;
	i = map->count_line - 1;
	while (map->tab[i][j])
	{
		if (map->tab[i][j] != '1' && map->tab[i][j] != ' ')
			return (1);
		j++;
	}
	return (0);
}

int	check_valid_map(t_map *map)
{
	if (check_valid_spawn(map))
		return (printf("Error : to few/many players.\n"));
	if (check_valid_char(map))
		return (printf("Error : bad character.\n"));
	if (check_valid_top(map))
		return (printf("Error : The map is not surrounded by walls.\n"));
	if (check_valid_bottom(map))
		return (printf("Error : The map is not surrounded by walls.\n"));
	if (check_valid_walls(map))
		return (printf("Error : The map is not surrounded by walls.\n"));
	if (check_valid_spaces(map))
		return (printf("Error : Invalid character(s) around spaces.\n"));
	return (0);
}