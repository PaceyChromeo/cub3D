/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:21:30 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/13 16:04:39 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	replace_closest_point(t_raycast *raycast, double next_x, double next_y)
{
	raycast->rx = next_x;
	raycast->ry = next_y;
}

void	keep_closest_point(t_raycast *raycast, double next_x, double next_y)
{
	if (raycast->ra >= 0 && raycast->ra < PI / 2)
	{
		if ((next_x < raycast->rx && next_y < raycast->ry) || raycast->ra == 0)
		{
			printf("SOUTH EAST\n");
			replace_closest_point(raycast, next_x, next_y);
		}
	}
	else if (raycast->ra > PI / 2 && raycast->ra < PI)
	{
		if (next_x > raycast->rx && next_y < raycast->ry)
		{
			printf("SOUTH WEST\n");
			replace_closest_point(raycast, next_x, next_y);
		}
	}
	else if (raycast->ra >= PI && raycast->ra < (PI + (PI / 2)))
	{
		if ((next_x > raycast->rx && next_y > raycast->ry) || raycast->ra == PI)
		{
			printf("NORTH WEST\n");
			replace_closest_point(raycast, next_x, next_y);
		}
	}
	else if (raycast->ra > (PI + (PI / 2)) && raycast->ra < 2 * PI)
	{
		if (next_x < raycast->rx && next_y > raycast->ry)
		{
			printf("NORTH EAST\n");
			replace_closest_point(raycast, next_x, next_y);
		}
	}
}

void	draw_rays(t_map *map)
{
	double	ray;
	int		i;

	// ray = map->player->angle;
	// map->raycast->ra = ray;
	// check_walls(map, map->raycast);
	// printf("raycast->rx : %f raycast->ry : %f\n", map->raycast->rx, map->raycast->ry);
	// draw_line(map, map->raycast->rx, map->raycast->ry, WHITE);
	ray = map->player->angle - convert_degre_to_radian(30);
	if (ray > 2 * PI)
		ray -= 2 * PI;
	else if (ray < 0)
		ray += 2 * PI;
	i = 0;
	while (i < 60)
	{
		map->raycast->ra = ray;
		check_walls(map, map->raycast);
		printf("raycast->rx : %f raycast->ry : %f\n", map->raycast->rx, map->raycast->ry);
		draw_line(map, map->raycast->rx, map->raycast->ry, WHITE);	
		ray += convert_degre_to_radian(1);
		if (ray > 2 * PI)
			ray -= 2 * PI;
		else if (ray < 0)
			ray += 2 * PI; 
		i++;
	}
}

void	raycasting(t_map *map)
{
	map->raycast = ft_calloc(sizeof(t_raycast), 1);
	if (!map->raycast)
		return ;
	map->raycast->ra = 0.0;
	map->raycast->rx = 0.0;
	map->raycast->ry = 0.0;
	map->raycast->coord_x = 0;	
	map->raycast->coord_y = 0;
	draw_rays(map);
}