/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:55:14 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/08 17:00:32 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	deal_up_key(t_map *map)
{
	map->player->pos_y -= 10;
}

void	deal_left_key(t_map *map)
{
	map->player->pos_x -= 10;
}

void	deal_down_key(t_map *map)
{
	map->player->pos_y += 10;
}

void	deal_right_key(t_map *map)
{
	map->player->pos_x += 10;
}
