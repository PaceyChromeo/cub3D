/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:55:45 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/08 18:53:13 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static t_img	*minimap_init(t_map *map)
{
	t_img	*minimap;
	
	minimap = ft_calloc(sizeof(t_img), 1);
	if (!minimap)
		return (NULL);
	minimap->img_ptr = mlx_new_image(map->mlx_ptr, 1200, 800);
	minimap->adr = mlx_get_data_addr(minimap->img_ptr,
					&minimap->bpp, &minimap->line_length, &minimap->endian);
	minimap->line = 800 / map->count_line;
	minimap->column = 1200 / map->line_length;
	return (minimap);
}

static void	display_minimap(t_map *map)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	i = 0;
	while (map->tab[i])
	{
		x = 0;
		j = 0;
		while (map->tab[i][j])
		{
			if (map->tab[i][j] == ' ')
				draw_square(map, x, y, 0x0);
			else if (map->tab[i][j] == '1') 
				draw_square(map, x, y, 0xff0000);
			else if (map->tab[i][j] == '0') 
				draw_square(map, x, y, 0x0000ff);
			x += map->minimap->column;
			j++;
		}
		y += map->minimap->line;
		i++;
	}
}

int	get_minimap(t_map *map)
{
	map->minimap = minimap_init(map);
	if (!map->minimap)
		return (1);
	display_minimap(map);
	return (0);
}
