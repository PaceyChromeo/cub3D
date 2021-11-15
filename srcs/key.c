/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 110:1010:14 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/12 12:08:46 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	deal_up_key(t_map *map)
{
	double	x;
	double	y;

	x = map->player->pos_x + map->player->delta_x;
	y = map->player->pos_y + map->player->delta_y;
	if (x > 0 && y > 0
		&& x < map->line_length * map->minimap->square
		&& y < map->count_line * map->minimap->square)
	{
		map->player->pos_x = x;
		map->player->pos_y = y;
	}
}

void	deal_left_key(t_map *map)
{
	double	x;
	double	y;

	x = cos(map->player->angle - (PI / 2)) * 10;
	y = sin(map->player->angle - (PI / 2)) * 10;
	x += map->player->pos_x;
	y += map->player->pos_y;
	if (x > 0 && y > 0
		&& x < map->line_length * map->minimap->square
		&& y < map->count_line * map->minimap->square)	
	{
		map->player->pos_x = x;
		map->player->pos_y = y;
	}
}

void	deal_down_key(t_map *map)
{
	double	x;
	double	y;

	x = map->player->pos_x - map->player->delta_x;
	y = map->player->pos_y - map->player->delta_y;
	if (x > 0 && y > 0
		&& x < map->line_length * map->minimap->square
		&& y < map->count_line * map->minimap->square)
	{
		map->player->pos_x = x;
		map->player->pos_y = y;
	}
}

void	deal_right_key(t_map *map)
{
	double	x;
	double	y;

	x = cos(map->player->angle + (PI / 2)) * 10;
	y = sinf(map->player->angle + (PI / 2)) * 10;
	x += map->player->pos_x;
	y += map->player->pos_y;
	if (x > 0 && y > 0
		&& x < map->line_length * map->minimap->square
		&& y < map->count_line * map->minimap->square)
	{
		map->player->pos_x = x;
		map->player->pos_y = y;
	}
}

void	deal_left_arrow(t_map *map)
{
	map->player->angle -= 0.1;
	if (map->player->angle < 0)
		map->player->angle += 2 * PI;
	map->player->delta_x = cosf(map->player->angle) * 10;
	map->player->delta_y = sinf(map->player->angle) * 10;
}

void	deal_right_arrow(t_map *map)
{
	map->player->angle += 0.1;
	if (map->player->angle > 2 * PI)
		map->player->angle -= 2 * PI;
	map->player->delta_x = cosf(map->player->angle) * 10;
	map->player->delta_y = sinf(map->player->angle) * 10;
}
