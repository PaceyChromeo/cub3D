/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrifa <hkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:47:48 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/16 12:21:55 by hkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

t_img	*cub_init(t_map *map)
{
	t_img	*cub;
	cub = ft_calloc(sizeof(t_img), 1);
	if (!cub)
		return (NULL);
	cub->img_ptr = mlx_new_image(map->mlx_ptr, SCREEN_W, SCREEN_H);
	cub->adr = mlx_get_data_addr(cub->img_ptr, &cub->bpp, &cub->line_length, &cub->endian);
	cub->fl = convert_rgb_floor(map);
	cub->ceil = convert_rgb_ceiling(map);
	return (cub);
}

static void	draw_floor(t_img *cub, double half_wall, int i)
{
	int	j;
	int	x;

	j = SCREEN_H / 2;
	x = j;
	while (j < x + half_wall)
	{
		ft_put_pixel(cub, i, j, BLACK);
		j++;
	}
	while (j < SCREEN_H)
	{
		ft_put_pixel(cub, i, j, cub->fl);
		j++;
	}
}

static void	draw_ceiling(t_img *cub, double half_wall, int i)
{
	int	j;
	int	ceiling;

	j = 0;
	ceiling = (SCREEN_H / 2) - half_wall;
	while (j < ceiling)
	{
		ft_put_pixel(cub, i, j, cub->ceil);
		j++;
	}
	while (j < (SCREEN_H / 2))
	{
		ft_put_pixel(cub, i, j, BLACK);
		j++;
	}
}

static double	distance_to_wall(t_map *map)
{
	double	wall_height;

	wall_height = 0.0;
	map->dpp = (SCREEN_W / 2) / tan(convert_degre_to_radian(30));
	map->dist = 0.0;
	
	map->dist = sqrt(square_dble(map->player->pos_x - map->raycast->rx) +
		square_dble(map->player->pos_y - map->raycast->ry));
	map->dist *= cos(map->raycast->ra - map->player->angle);
	wall_height = ceil((map->minimap->square * map->dpp) / map->dist);
	return (wall_height);
}

void	draw_walls(t_map *map, int i)
{
	int		j;
	double	wall_height;

	wall_height = distance_to_wall(map) / 2;
	if (wall_height > 0 && wall_height <= (SCREEN_H / 2))
	{
		draw_floor(map->cub, wall_height, i);
		draw_ceiling(map->cub, wall_height, i);
	}
	else
	{
		j = 0;
		while (j < SCREEN_H)
		{
			ft_put_pixel(map->cub, i, j, BLACK);
			j++;
		}
	}	
}