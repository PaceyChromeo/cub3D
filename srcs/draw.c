/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:44:11 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/08 18:54:34 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	draw_square(t_map *map, int x, int y, int color)
{
	int	heigth;
	int	width;
	int	i;

	heigth = y + map->minimap->line;
	width = x + map->minimap->column;
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