/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_arrow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:14:52 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/15 11:15:18 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

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
