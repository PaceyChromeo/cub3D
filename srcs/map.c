/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrifa <hkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:05:40 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/05 15:36:31 by hkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	get_tabnorm(char *tab, char **tmp, t_map *map, char *line)
{
	int	i;
	int	fd;

	i = 0;
	free(line);
	fd = open(tab, O_RDONLY);
	while (i < map->count_line)
	{
		get_next_line(fd, &line);
		tmp[i] = ft_strdup(line);
		i++;
		free(line);
	}
}

char	**get_tab(char *tab, t_map *map)
{
	char	*line;
	char	**tmp;
	int		fd;

	line = NULL;
	map->count_line = 1;
	fd = open(tab, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		map->count_line++;
		free(line);
	}
	tmp = ft_calloc(sizeof(tmp), map->count_line + 1);
	if (!tmp)
		return (0);
	get_tabnorm(tab, tmp, map, line);
	return (tmp);
}

static t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)ft_calloc(sizeof(*map), 1);
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
	return (map);
}

t_map	*get_map(int fd)
{
	t_map	*map;
	int i;
	int j;
	int count;
	char **tmp;
	(void)fd;
	
	i = 0;
	j = 0;
	count = 0;
	map = map_init();
	if (!map)
		return (NULL);
	// if (get_textures(fd, map))
	// 	return (NULL);
	tmp = get_tab("map.cub", map);
	while (tmp[i])
	{
		if (tmp[i][0] == '1' || tmp[i][0] == ' ')
			count++;
		i++;
	}
	map->tab = malloc(sizeof(map->tab) * count + 1);
	i = 0;
	while (tmp[i])
	{
		if (tmp[i][0] == '1' || tmp[i][0] == ' ')
		{
			map->tab[j] = ft_strdup(tmp[i]);
			free(tmp[i]);
			j++;
		}
		i++;
	}
	map->tab[j] = NULL;
	map->count_line = count;
	free(tmp);
	return (map);
}