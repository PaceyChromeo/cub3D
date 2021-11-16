/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrifa <hkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:05:09 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/16 12:17:47 by hkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	img_loop(t_map *map)
{
	//display_minimap(map, 0, 0);
	//draw_player(map, map->player->pos_x, map->player->pos_y, PURPLE);
	draw_rays(map);
	//mlx_put_image_to_window(map->mlx_ptr,
	// 	map->mlx_win, map->minimap->img_ptr, 0, 0);
	mlx_put_image_to_window(map->mlx_ptr,
		map->mlx_win, map->cub->img_ptr, 0, 0);
	return (0);
}
