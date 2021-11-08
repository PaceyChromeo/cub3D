/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrifa <hkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:22:35 by hkrifa            #+#    #+#             */
/*   Updated: 2021/11/08 17:57:55 by hkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int check_line(char *line)
{
	int i;
	
	i = 0;
	while (line[i])
	{
		if (line[0] == '1' || line[0] == ' ')
		{
			i++;
			if (line[i] == '1' || line[i] == ' ')
				return (1);
		}
		i++;
	}
	return (0);
}

static void	get_tabnorm(char **tmp, t_map *map)
{
	int	i;
	int	fd;
	char *line;
	
	i = 0;
	fd = open(map->map_name, O_RDONLY);
	while (i < map->count_line)
	{
		get_next_line(fd, &line);
		tmp[i] = ft_strdup(line);
		i++;
		free(line);
	}
	close (fd);
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
	free(line);
	close (fd);
	fd = open(map->map_name, O_RDONLY);
	tmp = ft_calloc(sizeof(tmp), map->count_line + 1);
	if (!tmp)
		return (0);
	get_tabnorm(tmp, map);
	return (tmp);
}

int	get_tab(t_map *map)
{
	int i;
	int j;
	int k;
	int count;
	char **tmp;

	i = 0;
	j = 0;
	k = 0;
	count = 0;
	tmp = get_tab_tmp(map);
	while (tmp[i])
	{
		if (check_line(tmp[i]))
		{
			k = i;
			break ;
		}
		free(tmp[i]);
		i++;
	}
	while (tmp[i])
	{
			count++;
		i++;
	}
	map->tab = malloc(sizeof(map->tab) * count + 1);
	while (tmp[k])
	{
		map->tab[j] = ft_strdup(tmp[k]);
		free(tmp[k]);
		j++;
		k++;
	}                                                                                                                                                                        
	map->tab[j] = NULL;
	map->count_line = count;
	free(tmp);
	return (0);
}