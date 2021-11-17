/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:00:03 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/17 17:09:24 by pjacob           ###   ########.fr       */
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
				map->player->pos_x
					= x * map->minimap->square + map->minimap->square / 2;
				map->player->pos_y
					= y * map->minimap->square + map->minimap->square / 2;
				map->tab[y][x] = '0';
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

static int	get_player_angle(t_map *map)
{
	if (map->pl_view == 'N')
		map->player->angle = PI + (PI / 2);
	else if (map->pl_view == 'S')
		map->player->angle = PI / 2;
	else if (map->pl_view == 'W')
		map->player->angle = PI;
	else if (map->pl_view == 'E')
		map->player->angle = 0;
	map->player->delta_x = cos(map->player->angle) * 5;
	map->player->delta_y = sin(map->player->angle) * 5;
	return (0);
}

int	get_player(t_map *map)
{
	map->player = ft_calloc(sizeof(*map->player), 1);
	get_player_position(map);
	get_player_angle(map);
	draw_player(map, map->player->pos_x, map->player->pos_y, SILVER);
	return (0);
}
