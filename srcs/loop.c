/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:05:09 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/08 17:12:41 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	img_loop(t_map *map)
{
	ft_put_pixel(map->minimap, map->player->pos_x, map->player->pos_y, 0xff0000);
	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->minimap->img_ptr, 0, 0);
	return (0);
}
