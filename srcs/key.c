/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:55:14 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/09 14:36:26 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	deal_up_key(t_map *map)
{
	map->player->pos_x += map->player->delta_x;
	map->player->pos_y += map->player->delta_y;
	
}

void	deal_left_key(t_map *map)
{
	map->player->pos_x -= map->player->delta_x;
}

void	deal_down_key(t_map *map)
{
	map->player->pos_x -= map->player->delta_x;
	map->player->pos_y -= map->player->delta_y;
}

void	deal_right_key(t_map *map)
{
	map->player->pos_x += map->player->delta_x;
}

void	deal_left_arrow(t_map *map)
{
	map->player->angle -= 0.1;
	if (map->player->angle < 0)
		map->player->angle += 2 * PI;
	map->player->delta_x = cos(map->player->angle) * 10;
	map->player->delta_y = sin(map->player->angle) * 10;
}

void	deal_right_arrow(t_map *map)
{
	map->player->angle += 0.1;
	if (map->player->angle > 2 * PI)
		map->player->angle -= 2 * PI;
	map->player->delta_x = cos(map->player->angle) * 10;
	map->player->delta_y = sin(map->player->angle) * 10;
}
