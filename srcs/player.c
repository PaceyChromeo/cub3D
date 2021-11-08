/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:00:03 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/08 17:39:10 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	get_player_position(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->tab[y])
	{
		x = 0;
		while (map->tab[y][x])
		{
			if (map->tab[y][x] == 'S' || map->tab[y][x] == 'N'
				|| map->tab[y][x] == 'W' || map->tab[y][x] == 'E')
			{
				map->player->pos_x = x * map->minimap->column;			
				map->player->pos_y = y * map->minimap->line;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	get_player(t_map *map)
{
	map->player = ft_calloc(sizeof(*map->player), 1);
	get_player_position(map);
	return (0);
}
