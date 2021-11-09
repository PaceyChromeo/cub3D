/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:00:03 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/09 15:24:43 by pjacob           ###   ########.fr       */
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

static int	get_player_angle(t_map *map)
{
	if (map->pl_view == 'S')
		map->player->angle = PI + (PI / 2);
	else if (map->pl_view == 'N')
		map->player->angle = PI / 2;
	else if (map->pl_view == 'W')
		map->player->angle = PI;
	else if (map->pl_view == 'E')
		map->player->angle = 0;
	map->player->delta_x = cos(map->player->angle) * 10;
	map->player->delta_y = sin(map->player->angle) * 10;
	return (0);
}

void	display_player(t_map *map)
{
	double	x;
	double	y;

	x = map->player->pos_x + (map->minimap->column / 2);
	y = map->player->pos_y + (map->minimap->line / 2);
	draw_player(map, x, y, SILVER);
	draw_line(map, x, y, PURPLE);
}

int	get_player(t_map *map)
{
	map->player = ft_calloc(sizeof(*map->player), 1);
	get_player_position(map);
	get_player_angle(map);
	display_player(map);
	return (0);
}
