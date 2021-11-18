/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:02:49 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/18 12:54:57 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	check_horizontal_looking_up(t_map *map,
		t_raycast *raycast, double next_x, double next_y)
{
	next_y = floor(map->player->pos_y / map->minimap->square)
		* map->minimap->square - 0.000001;
	if (map->player->pos_x - ((map->player->pos_y - next_y)
			/ tan(raycast->ra)) < 0)
		next_x = 0;
	else if (map->player->pos_x - ((map->player->pos_y - next_y)
			/ tan(raycast->ra)) > SCREEN_W * map->minimap->square)
		next_x = SCREEN_W * map->minimap->square;
	else
		next_x = map->player->pos_x - ((map->player->pos_y - next_y)
			/ tan(raycast->ra));
	raycast->coord_x = next_x / map->minimap->square;
	raycast->coord_y = next_y / map->minimap->square;
	while (map->tab[raycast->coord_y][raycast->coord_x] == '0'
		&& next_x > 0 && raycast->coord_x > 0 && raycast->coord_y > 0
		&& next_x < map->line_length * map->minimap->square
		&& next_y > 0)
	{
		next_x -= (map->minimap->square / tan(raycast->ra));
		next_y -= map->minimap->square;
		raycast->coord_x = next_x / map->minimap->square;
		raycast->coord_y = next_y / map->minimap->square;
	}
	raycast->rx = next_x;
	raycast->ry = next_y;
}

static void	check_horizontal_looking_down(t_map *map,
		t_raycast *raycast, double next_x, double next_y)
{
	next_y = floor(map->player->pos_y / map->minimap->square)
		* (map->minimap->square) + map->minimap->square;
	if (map->player->pos_x - ((map->player->pos_y - next_y)
			/ tan(raycast->ra)) < 0)
		next_x = 0;
	else if (map->player->pos_x - ((map->player->pos_y - next_y)
			/ tan(raycast->ra)) > SCREEN_W * map->minimap->square)
		next_x = SCREEN_W * map->minimap->square;
	else
		next_x = map->player->pos_x - ((map->player->pos_y - next_y)
			/ tan(raycast->ra));
	raycast->coord_x = next_x / map->minimap->square;
	raycast->coord_y = next_y / map->minimap->square;
	while (map->tab[raycast->coord_y][raycast->coord_x] == '0'
		&& next_x > 0 && raycast->coord_x > 0 && raycast->coord_y > 0
		&& next_x < map->line_length * map->minimap->square
		&& next_y < map->count_line * map->minimap->square)
	{
		next_x += (map->minimap->square / tan(raycast->ra));
		next_y += map->minimap->square;
		raycast->coord_x = next_x / map->minimap->square;
		raycast->coord_y = next_y / map->minimap->square;
	}
	raycast->rx = next_x;
	raycast->ry = next_y;
}

static void	check_vertical_looking_left(t_map *map,
		t_raycast *raycast, double next_x, double next_y)
{
	next_x = floor(map->player->pos_x / map->minimap->square)
		* (map->minimap->square) - 0.000001;
	next_y = map->player->pos_y - ((map->player->pos_x - next_x)
			* tan(raycast->ra));
	raycast->coord_x = next_x / map->minimap->square;
	raycast->coord_y = next_y / map->minimap->square;
	while (next_x > 0 && next_y > 0
		&& raycast->coord_x > 0 && raycast->coord_y > 0
		&& next_x < map->line_length * map->minimap->square
		&& next_y < map->count_line * map->minimap->square
		&& map->tab[raycast->coord_y][raycast->coord_x] == '0')
	{
		next_y -= (map->minimap->square * tan(raycast->ra));
		next_x -= map->minimap->square;
		raycast->coord_x = next_x / map->minimap->square;
		raycast->coord_y = next_y / map->minimap->square;
	}
	keep_closest_point(raycast, next_x, next_y);
}

static void	check_vertical_looking_right(t_map *map,
		t_raycast *raycast, double next_x, double next_y)
{
	next_x = floor(map->player->pos_x / map->minimap->square)
		* (map->minimap->square) + map->minimap->square;
	next_y = map->player->pos_y - ((map->player->pos_x - next_x)
			* tan(raycast->ra));
	raycast->coord_x = next_x / map->minimap->square;
	raycast->coord_y = next_y / map->minimap->square;
	while (next_x > 0 && next_y > 0
		&& raycast->coord_x > 0 && raycast->coord_y > 0
		&& next_x < map->line_length * map->minimap->square
		&& next_y < map->count_line * map->minimap->square
		&& map->tab[raycast->coord_y][raycast->coord_x] == '0')
	{
		next_y += (map->minimap->square * tan(raycast->ra));
		next_x += map->minimap->square;
		raycast->coord_x = next_x / map->minimap->square;
		raycast->coord_y = next_y / map->minimap->square;
	}
	keep_closest_point(raycast, next_x, next_y);
}

void	check_walls(t_map *map, t_raycast *raycast)
{
	double	next_x;
	double	next_y;

	next_x = 0.0;
	next_y = 0.0;
	if (raycast->ra != 0 && raycast->ra != PI)
	{
		if (raycast->ra < PI)
			check_horizontal_looking_down(map, raycast, next_x, next_y);
		else if (raycast->ra > PI)
			check_horizontal_looking_up(map, raycast, next_x, next_y);
	}
	if (raycast->ra > PI / 2 && raycast->ra < (PI + (PI / 2)))
		check_vertical_looking_left(map, raycast, next_x, next_y);
	else if (raycast->ra < PI / 2 || raycast->ra > (PI + (PI / 2)))
		check_vertical_looking_right(map, raycast, next_x, next_y);
}
