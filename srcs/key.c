/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:10:10 by by pjacob         #+#    #+#             */
/*   Updated: 2021/11/17 11:42:54 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	deal_up_key(t_map *map)
{
	double	x;
	double	y;
	int		cx;
	int		cy;

	x = map->player->pos_x + map->player->delta_x;
	y = map->player->pos_y + map->player->delta_y;
	if (x > 0 && y > 0
		&& x < map->line_length * map->minimap->square
		&& y < (map->count_line * map->minimap->square)
		- map->minimap->square)
	{
		cx = (int)(x / map->minimap->square);
		cy = (int)(y / map->minimap->square);
		if (map->tab[cy][cx] && map->tab[cy][cx] == '0')
		{
			map->player->pos_x = x;
			map->player->pos_y = y;
		}
	}
}

void	deal_left_key(t_map *map)
{
	double	x;
	double	y;
	int		cx;
	int		cy;

	x = cos(map->player->angle - (PI / 2)) * 10;
	y = sin(map->player->angle - (PI / 2)) * 10;
	x += map->player->pos_x;
	y += map->player->pos_y;
	if (x > 0 && y > 0
		&& x < map->line_length * map->minimap->square
		&& y < (map->count_line * map->minimap->square)
		- map->minimap->square)
	{
		cx = (int)(x / map->minimap->square);
		cy = (int)(y / map->minimap->square);
		if (map->tab[cy][cx] && map->tab[cy][cx] == '0')
		{
			map->player->pos_x = x;
			map->player->pos_y = y;
		}
	}
}

void	deal_down_key(t_map *map)
{
	double	x;
	double	y;
	int		cx;
	int		cy;

	x = map->player->pos_x - map->player->delta_x;
	y = map->player->pos_y - map->player->delta_y;
	if (x > 0 && y > 0
		&& x < map->line_length * map->minimap->square
		&& y < (map->count_line * map->minimap->square)
		- map->minimap->square)
	{
		cx = (int)(x / map->minimap->square);
		cy = (int)(y / map->minimap->square);
		if (map->tab[cy][cx] && map->tab[cy][cx] == '0')
		{
			map->player->pos_x = x;
			map->player->pos_y = y;
		}
	}
}

void	deal_right_key(t_map *map)
{
	double	x;
	double	y;
	int		cx;
	int		cy;

	x = cos(map->player->angle + (PI / 2)) * 5;
	y = sinf(map->player->angle + (PI / 2)) * 5;
	x += map->player->pos_x;
	y += map->player->pos_y;
	if (x > 0 && y > 0
		&& x < map->line_length * map->minimap->square
		&& y < (map->count_line * map->minimap->square)
		- map->minimap->square)
	{
		cx = (int)(x / map->minimap->square);
		cy = (int)(y / map->minimap->square);
		if (map->tab[cy][cx] && map->tab[cy][cx] == '0')
		{
			map->player->pos_x = x;
			map->player->pos_y = y;
		}
	}
}
