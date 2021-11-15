/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:47:48 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/15 15:28:36 by pjacob           ###   ########.fr       */
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
		ft_put_pixel(cub, i, j, RED);
		j++;
	}
	while (j < 400)
	{
		ft_put_pixel(cub, i, j, BLACK);
		j++;
	}
}

static void	draw_ceiling(t_img *cub, double half_wall, int i)
{
	int	j;
	int	ceiling;

	j = 0;
	ceiling = 200 - half_wall;
	while (j < ceiling)
	{
		ft_put_pixel(cub, i, j, BLACK);
		j++;
	}
	while (j < 200)
	{
		ft_put_pixel(cub, i, j, RED);
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
	double	wall_height;
	int		j;

	wall_height = distance_to_wall(map) / 2;
	if (wall_height > 0 && wall_height <= 200)
	{
		draw_floor(map->cub, wall_height, i);
		draw_ceiling(map->cub, wall_height, i);
	}
	else
	{
		j = 0;
		while (j < 400)
		{
			ft_put_pixel(map->cub, i, j, RED);
			j++;
		}
	}	
}