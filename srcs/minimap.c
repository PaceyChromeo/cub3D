/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:55:45 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/08 17:44:02 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static t_img	*minimap_init(t_map *map)
{
	t_img	*minimap;
	
	minimap = ft_calloc(sizeof(t_img), 1);
	if (!minimap)
		return (NULL);
	minimap->img_ptr = mlx_new_image(map->mlx_ptr, 800, 600);
	minimap->adr = mlx_get_data_addr(minimap->img_ptr,
					&minimap->bpp, &minimap->line_length, &minimap->endian);
	minimap->line = 600 / map->count_line;
	minimap->column = 800 / map->line_length;
	return (minimap);
}

static void	display_minimap(char **tab)
{
	int	x;
	int	y;

	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			
			x++;
		}
		y++;
	}
}

t_img	*get_minimap(t_map *map)
{
	t_img	*minimap;

	minimap = minimap_init(map);
	if (!minimap)
		return (NULL);
	display_minimap(map->tab);
	return (minimap);
}
