/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacey <pacey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:21:30 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/24 21:45:17 by pacey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	replace_closest_point(
		t_raycast *raycast, double next_x, double next_y, int i)
{
	if (raycast->wall_hit == 1 && i == 0)
		raycast->wall_hit = 2;
	else if (raycast->wall_hit == 1 && i == 1)
		raycast->wall_hit = 3;
	else if (raycast->wall_hit == 0 && i == 2)
		raycast->wall_hit = 3;
	else if (raycast->wall_hit == 0 && i == 3)
		raycast->wall_hit = 2;
	raycast->rx = next_x;
	raycast->ry = next_y;
}

void	keep_closest_point(t_raycast *raycast, double next_x, double next_y)
{
	if (raycast->ra >= 0 && raycast->ra < PI / 2)
	{
		raycast->wall_hit = 1;
		if ((next_x < raycast->rx && next_y < raycast->ry) || raycast->ra == 0)
			replace_closest_point(raycast, next_x, next_y, 0);
	}
	else if (raycast->ra > PI / 2 && raycast->ra < PI)
	{
		raycast->wall_hit = 1;
		if (next_x > raycast->rx && next_y < raycast->ry)
			replace_closest_point(raycast, next_x, next_y, 1);
	}
	else if (raycast->ra >= PI && raycast->ra < (PI + (PI / 2)))
	{
		raycast->wall_hit = 0;
		if ((next_x > raycast->rx && next_y > raycast->ry) || raycast->ra == PI)
			replace_closest_point(raycast, next_x, next_y, 2);
	}
	else if (raycast->ra > (PI + (PI / 2)) && raycast->ra < 2 * PI)
	{
		raycast->wall_hit = 0;
		if (next_x < raycast->rx && next_y > raycast->ry)
			replace_closest_point(raycast, next_x, next_y, 3);
	}
}

void	draw_rays(t_map *map)
{
	double	ray;
	int		i;

	ray = map->player->angle - convert_degre_to_radian(30);
	if (ray > 2 * PI)
		ray -= 2 * PI;
	else if (ray < 0)
		ray += 2 * PI;
	i = 0;
	while (i < SCREEN_W)
	{
		map->raycast->ra = ray;
		check_walls(map, map->raycast);
		draw_walls(map, i);
		ray += convert_degre_to_radian(0.1);
		if (ray > 2 * PI)
			ray -= 2 * PI;
		else if (ray < 0)
			ray += 2 * PI;
		i++;
	}
}

int	raycasting(t_map *map)
{
	map->raycast = ft_calloc(sizeof(t_raycast), 1);
	if (!map->raycast)
		return ;
	map->cub = ft_calloc(sizeof(t_img), 1);
	if (!map->cub)
		return ;
	map->raycast->ra = 0.0;
	map->raycast->rx = 0.0;
	map->raycast->ry = 0.0;
	map->raycast->coord_x = 0;
	map->raycast->coord_y = 0;
	map->raycast->wall_hit = 0;
	if (cub_init(map))
		return (1);
	draw_rays(map);
	return (0);
}
