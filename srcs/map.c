/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:05:40 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/15 15:18:40 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static t_map	*map_init(t_map *map, char *av)
{
	map->mlx_ptr = NULL;
	map->mlx_win = NULL;
	map->north_text = NULL;
	map->south_text = NULL;
	map->west_text = NULL;
	map->east_text = NULL;
	map->floor = (int *)ft_calloc(sizeof(int), 3);
	if (!map->floor)
		return (NULL);
	ft_memset((int *)map->floor, 0, 3);
	map->ceiling = (int *)ft_calloc(sizeof(int), 3);
	if (!map->ceiling)
		return (NULL);
	ft_memset((int *)map->ceiling, 0, 3);
	map->map_name = av;
	map->line_length = 0;
	map->count_line = 0;
	map->i = 0;
	map->minimap = NULL;
	map->player = NULL;
	map->raycast = NULL;
	map->cub = NULL;
	return (map);
}

t_map	*get_map(int fd, char *av)
{
	t_map	*map;

	map = (t_map *)(ft_calloc(sizeof(*map), 1));
	if (!map)
		return (NULL);
	map_init(map, av);
	if (!map)
		return (NULL);
	if (get_textures(fd, map))
		return (NULL);
	if (get_colors(fd, map))
		return (NULL);
	if (get_tab(map))
		return (NULL);
	if (check_valid_map(map))
		return (NULL);
	return (map);
}
