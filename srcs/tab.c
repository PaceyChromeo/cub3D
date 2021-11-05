/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:54:53 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/05 17:05:22 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	get_tabnorm(char **tmp, t_map *map, char *line)
{
	int	i;
	int	fd;

	i = 0;
	free(line);
	fd = open(map->map_name, O_RDONLY);
	while (i < map->count_line)
	{
		get_next_line(fd, &line);
		tmp[i] = ft_strdup(line);
		i++;
		free(line);
	}
}

static char	**get_tab_tmp(t_map *map)
{
	char	*line;
	char	**tmp;
	int		fd;

	line = NULL;
	map->count_line = 1;
	fd = open(map->map_name, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		map->count_line++;
		free(line);
	}
	tmp = ft_calloc(sizeof(tmp), map->count_line + 1);
	if (!tmp)
		return (0);
	get_tabnorm(tmp, map, line);
	return (tmp);
}

int	get_tab(t_map *map)
{
	int i;
	int j;
	int count;
	char **tmp;

	i = 0;
	j = 0;
	count = 0;
	tmp = get_tab_tmp(map);
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
	return (0);
}