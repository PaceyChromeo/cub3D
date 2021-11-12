/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:21:30 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/12 17:35:10 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static t_raycast	*init_raycasting(void)
{
	t_raycast	*raycast;

	raycast = ft_calloc(sizeof(t_raycast), 1);
	if (!raycast)
		return (NULL);
	raycast->ra = 0;	
	raycast->coord_x = 0;	
	raycast->coord_y = 0;	
	return (raycast);
}

static void	check_horizontal_line(t_map *map, t_raycast *raycast)
{
	double	next_x;
	double	next_y;

	next_x = 0.0;
	next_y = 0.0;
	if (raycast->ra < PI) // looking down
	{
		printf("DOWN\n");
 		printf("angle : %f\n", convert_radian_to_degre(raycast->ra));
 		printf("pos_x : %f pos_y : %f\n", map->player->pos_x, map->player->pos_y);
 		printf("tan : %f\n", tan(raycast->ra));
		next_y = floor(map->player->pos_y / map->minimap->square) * (map->minimap->square) + map->minimap->square;
		next_x = map->player->pos_x - ((map->player->pos_y - next_y) / tan(raycast->ra));
 		printf("next_x : %f : next_y : %f\n", next_x, next_y);
		raycast->coord_x = next_x / map->minimap->square;
		raycast->coord_y = next_y / map->minimap->square;
		printf("horizontal before down - map[%d][%d]\n", raycast->coord_y, raycast->coord_x);
		// while (map->tab[raycast->coord_y][raycast->coord_x]
		// 	&& map->tab[raycast->coord_y][raycast->coord_x] != '1')
		// {
		// 	printf("horizontal while down - map[%d][%d]\n", raycast->coord_y, raycast->coord_x);
 		// 	printf("while next_x : %f : next_y : %f\n", next_x, next_y);
		// 	next_x -= (map->minimap->square / tan(raycast->ra));
		// 	next_y += map->minimap->square;
		// 	raycast->coord_x = next_x / map->minimap->square;
		// 	raycast->coord_y = next_y / map->minimap->square;
		// }
		if (map->tab[raycast->coord_y][raycast->coord_x] == '1')
			printf("horizontal end down - map[%d][%d]\n", raycast->coord_y, raycast->coord_x);
	}
	else if (raycast->ra > PI) // looking up
	{
		printf("UP\n");
 		printf("angle : %f\n", convert_radian_to_degre(raycast->ra));
 		printf("pos_x : %f pos_y : %f\n", map->player->pos_x, map->player->pos_y);
 		printf("tan : %f\n", tan(raycast->ra));
		next_y = floor(map->player->pos_y / map->minimap->square) * map->minimap->square - 1;
		next_x = map->player->pos_x - ((map->player->pos_y - next_y) / tan(raycast->ra));
 		printf("next_x : %f : next_y : %f\n", next_x, next_y);
		raycast->coord_x = next_x / map->minimap->square;
		raycast->coord_y = next_y / map->minimap->square;
		printf("horizontal before up - map[%d][%d]\n", raycast->coord_y, raycast->coord_x);
		// while (map->tab[raycast->coord_y][raycast->coord_x]
		// 	&& map->tab[raycast->coord_y][raycast->coord_x] != '1')
		// {
		// 	printf("horizontal while up - map[%d][%d]\n", raycast->coord_y, raycast->coord_x);
		// 	next_x -= (map->minimap->square / tan(raycast->ra));
		// 	next_y -= map->minimap->square;
		// 	raycast->coord_x = next_x / map->minimap->square;
		// 	raycast->coord_y = next_y / map->minimap->square;
		// }
		if (map->tab[raycast->coord_y][raycast->coord_x] == '1')
			printf("horizontal end up - map[%d][%d]\n", raycast->coord_y, raycast->coord_x);
	}
	if (next_x < 0)
		next_x = 0;
	else if (next_x > SCREEN_H)
		next_x = SCREEN_W;
	draw_line(map, next_x, next_y, WHITE);
}

// static void	check_vertical_line(t_map *map, t_raycast *raycast)
// {
// 	double	next_x;
// 	double	next_y;

// 	if (raycast->ra == 90 || raycast->ra == 270)
// 		return ;
// 	else if (raycast->ra > 90 && raycast->ra < 270) // looking left
// 	{
// 		printf("angle : %f\n", raycast->ra);
// 		printf("pos_Y : %f pos_X : %f\n", map->player->pos_y, map->player->pos_x);
// 		next_x = floor(map->player->pos_x / map->minimap->square) * map->minimap->square - 1;
// 		next_y = map->player->pos_y + (map->player->pos_x - next_x) * tan(raycast->ra);
// 		printf("1 - next_x : %f : next_y : %f\n", next_x, next_y);
// 		raycast->coord_x = next_x / map->minimap->square;
// 		raycast->coord_y = next_y / map->minimap->square;
// 		printf("2 - next_x : %d : next_y : %d\n", (int)next_x, (int)next_y);
// 		printf("vertical before left - map[%d][%d]\n", raycast->coord_y, raycast->coord_x);
// 		while (map->tab[raycast->coord_y][raycast->coord_x]
// 			&& map->tab[raycast->coord_y][raycast->coord_x] != '1')
// 		{
// 			printf("vertical while left - map[%d][%d]\n", raycast->coord_y, raycast->coord_x);
// 			next_x -= map->minimap->square;
// 			next_y += map->minimap->square / tan(raycast->ra);
// 			raycast->coord_x = next_x / map->minimap->square;
// 			raycast->coord_y = next_y / map->minimap->square;
// 		}
// 		if (map->tab[raycast->coord_y][raycast->coord_x] == '1')
// 			printf("vertical end left - map[%d][%d]\n", raycast->coord_y, raycast->coord_x);
// 	}
// 	else if ((raycast->ra > 270 && raycast->ra < 360) || (raycast->ra > 0 && raycast->ra < 90)) // looking right
// 	{
// 		printf("angle : %f\n", raycast->ra);
// 		printf("pos_Y : %f pos_X : %f\n", map->player->pos_y, map->player->pos_x);
// 		next_x = floor(map->player->pos_x / map->minimap->square) * map->minimap->square + map->minimap->square;
// 		next_y = map->player->pos_y + (map->player->pos_x - next_x) * tan(raycast->ra);
// 		printf("1 - next_x : %f : next_y : %f\n", next_x, next_y);
// 		raycast->coord_x = next_x / map->minimap->square;
// 		raycast->coord_y = next_y / map->minimap->square;
// 		printf("2 - next_x : %d : next_y : %d\n", (int)next_x, (int)next_y);
// 		printf("vertical before right - map[%d][%d]\n", raycast->coord_y, raycast->coord_x);
// 		while (map->tab[raycast->coord_y][raycast->coord_x]
// 			&& map->tab[raycast->coord_y][raycast->coord_x] != '1')
// 		{
// 			printf("vertical while right - map[%d][%d]\n", raycast->coord_y, raycast->coord_x);
// 			next_x += map->minimap->square;
// 			next_y += map->minimap->square / tan(raycast->ra);
// 			raycast->coord_x = next_x / map->minimap->square;
// 			raycast->coord_y = next_y / map->minimap->square;
// 		}
// 		if (map->tab[raycast->coord_y][raycast->coord_x] == '1')
// 			printf("vertical end right - map[%d][%d]\n", raycast->coord_y, raycast->coord_x);
// 	}
// }

void	raycasting(t_map *map)
{
	t_raycast	*raycast;

	raycast = init_raycasting();
	if (!raycast)
		return ;
	raycast->ra = map->player->angle;
	if (raycast->ra != 0 && raycast->ra != PI)
		check_horizontal_line(map, raycast);
	//check_vertical_line(map, raycast);
}