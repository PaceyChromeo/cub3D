/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:47:48 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/17 17:04:58 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	cub_init(t_map *map)
{
	map->cub->img_ptr = mlx_new_image(map->mlx_ptr, SCREEN_W, SCREEN_H);
	map->cub->height = SCREEN_H;
	map->cub->width = SCREEN_W;
	map->cub->adr = mlx_get_data_addr(map->cub->img_ptr, &map->cub->bpp,
			&map->cub->line_length, &map->cub->endian);
	map->cub->fl = convert_rgb_floor(map);
	map->cub->ceil = convert_rgb_ceiling(map);
	if (init_texture(map))
		return (1);
	return (0);
}

static void	draw_floor(t_map *map, double half_wall, int i)
{
	int	j;
	int	x;
	int	color;

	j = SCREEN_H / 2;
	x = j;
	color = 0;
	while (j < (x + half_wall))
	{
		color = find_color_in_xpm_file(map, half_wall, j);
		ft_put_pixel(map->cub, i, j, color);
		j++;
	}
	while (j < SCREEN_H)
	{
		ft_put_pixel(map->cub, i, j, map->cub->fl);
		j++;
	}
}

static void	draw_ceiling(t_map *map, double half_wall, int i)
{
	int	j;
	int	ceiling;
	int	color;

	j = 0;
	color = 0;
	ceiling = (SCREEN_H / 2) - half_wall;
	while (j < ceiling)
	{
		ft_put_pixel(map->cub, i, j, map->cub->ceil);
		j++;
	}
	while (j < (SCREEN_H / 2))
	{
		color = find_color_in_xpm_file(map, half_wall, j);
		ft_put_pixel(map->cub, i, j, color);
		j++;
	}
}

static double	distance_to_wall(t_map *map)
{
	double	wall_height;

	wall_height = 0.0;
	map->dpp = (SCREEN_W / 2) / tan(convert_degre_to_radian(30));
	map->dist = 0.0;
	map->dist = sqrt(square_dble(map->player->pos_x - map->raycast->rx)
			+ square_dble(map->player->pos_y - map->raycast->ry));
	map->dist *= cos(map->raycast->ra - map->player->angle);
	wall_height = ceil((map->minimap->square * map->dpp) / map->dist);
	return (wall_height);
}

void	draw_walls(t_map *map, int i)
{
	int		j;
	double	wall_height;
	int		color;

	color = 0;
	wall_height = distance_to_wall(map) / 2;
	if (wall_height > 0 && wall_height <= (SCREEN_H / 2))
	{
		draw_ceiling(map, wall_height, i);
		draw_floor(map, wall_height, i);
	}
	else
	{
		j = 0;
		while (j < SCREEN_H)
		{
			color = find_color_in_xpm_file(map, wall_height, j);
			ft_put_pixel(map->cub, i, j, color);
			j++;
		}
	}	
}
