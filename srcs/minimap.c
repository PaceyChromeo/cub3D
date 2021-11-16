/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrifa <hkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:55:45 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/16 12:14:40 by hkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static t_img	*minimap_init(t_map *map)
{
	t_img	*minimap;

	minimap = ft_calloc(sizeof(t_img), 1);
	if (!minimap)
		return (NULL);
	minimap->img_ptr = mlx_new_image(map->mlx_ptr, SCREEN_W, SCREEN_H);
	minimap->adr = mlx_get_data_addr(minimap->img_ptr,
			&minimap->bpp, &minimap->line_length, &minimap->endian);
	minimap->line = SCREEN_H / map->count_line;
	minimap->column = SCREEN_W / map->line_length;
	if (minimap->line > minimap->column)
	 	minimap->square = floor(minimap->column);
	else
	 	minimap->square = floor(minimap->line);
	return (minimap);
}

void	display_minimap(t_map *map, int i, int y)
{
	int	x;
	int	j;
	
	while (map->tab[i])
	{
		x = 0;
		j = 0;
		while (map->tab[i][j])
		{
			if (map->tab[i][j] == ' ')
				draw_square(map, x, y, BLACK);
			else if (map->tab[i][j] == '1')
				draw_square(map, x, y, TEAL);
			else if (map->tab[i][j] == '0' || map->tab[i][j] == 'S'
				|| map->tab[i][j] == 'N'
				|| map->tab[i][j] == 'E' || map->tab[i][j] == 'W')
				draw_square(map, x, y, SILVER);
			x += map->minimap->square;
			j++;
		}
		y += map->minimap->square;
		i++;
	}
	draw_grid(map);
}

int	get_minimap(t_map *map)
{
	map->minimap = minimap_init(map);
	if (!map->minimap)
		return (1);
	display_minimap(map, 0, 0);
	return (0);
}
