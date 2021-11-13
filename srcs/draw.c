/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:44:11 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/13 15:11:55 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	draw_grid(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_H)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			ft_put_pixel(map->minimap, x, y, BLACK);
			x++;;
		}
		y += map->minimap->square;
	}
	y = 0;
	while (y < SCREEN_H)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			ft_put_pixel(map->minimap, x, y, BLACK);
			x += map->minimap->square;
		}
		y++;
	}
}

void	draw_square(t_map *map, int x, int y, int color)
{
	int	heigth;
	int	width;
	int	i;

	heigth = y + map->minimap->square;
	width = x + map->minimap->square;
	while (y < heigth)
	{
		i = x;	
		while (i < width)
		{
			ft_put_pixel(map->minimap, i, y, color);
			i++;
		}
		y++;
	}
}

void	draw_player(t_map *map, double x, double y, int color)
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	int	i;

	start_x = (int)x - (map->minimap->square / 10);
	start_y = (int)y - (map->minimap->square / 10);
	end_x = (int)x + (map->minimap->square / 10);
	end_y = (int)y + (map->minimap->square / 10);
	while (start_y <= end_y)
	{
		i = start_x;	
		while (i <= end_x)
		{
			ft_put_pixel(map->minimap, i, start_y, color);
			i++;
		}
		start_y++;
	}
}

void	draw_player_line(t_map *map, double x, double y, int color)
{
	int		step;
	double	incX;
	double	incY;
	int		i;

	if (fabs(map->player->delta_x) > fabs(map->player->delta_y))
		step = fabs(map->player->delta_x);
	else
		step = fabs(map->player->delta_y);
	incX = map->player->delta_x / (double)step;
	incY = map->player->delta_y / (double)step;
	i = 0;
	while (i <= step)
	{
		ft_put_pixel(map->minimap, x, y, color);
		x += incX;
		y += incY;
		i++;
	}
}

void	draw_line(t_map *map, double x, double y, int color)
{
	int		step;
	double	x0;
	double	y0;
	double	dX;
	double	dY;
	int		i;

	dX = x - map->player->pos_x;
	dY = y - map->player->pos_y;
	if (fabs(dX) >= fabs(dY))
		step = fabs(dX);
	else
		step = fabs(dY);
	dX /= (double)step;
	dY /= (double)step;
	i = 0;
	x0 = map->player->pos_x;
	y0 = map->player->pos_y;
	while (i <= step)
	{
		ft_put_pixel(map->minimap, x0, y0, color);
		x0 += dX;
		y0 += dY;
		i++;
	}
}