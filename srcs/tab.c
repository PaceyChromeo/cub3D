/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrifa <hkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:22:35 by hkrifa            #+#    #+#             */
/*   Updated: 2021/11/09 18:16:53 by hkrifa           ###   ########.fr       */
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
			if (line[i] != '1' && line[i] != ' ')
				return (0);
			while (line[i] == '1' || line[i] == ' ')
			{
				if (!line[i + 1])
					return (1);
				i++;
			}
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
		if (ft_strlen(tmp[i]) > (size_t)map->line_length)
			map->line_length = ft_strlen(tmp[i]);
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

char *get_line(char *line, int max)
{
	int i;
	int j;
	char *new;

	i = 0;
	j = ft_strlen(line);
	new = malloc(sizeof(new) * max + 1);
	while (line[i])
	{
		new[i] = line[i];
		i++;
	}
	if (j < max)
	{
		while (i < max)
		{
			new[i] = ' ';
			i++;
		}
	}
	new[i] = '\0';
	return (new);
}

int	get_tab(t_map *map)
{
	int i;
	int j;
	int index;
	int count;
	char **tmp;

	i = 0;
	j = 0;
	index = 0;
	tmp = get_tab_tmp(map);
	while (tmp[i])
	{
		if (check_line(tmp[i]))
		{
			index = i;
			break ;
		}
		free(tmp[i]);
		i++;
	}
	count = count_lines(tmp, i);
	map->tab = malloc(sizeof(map->tab) * count + 1);
	while (tmp[index])
	{
		map->tab[j] = get_line(tmp[index], get_max(tmp, i));
		free(tmp[index]);
		j++;
		index++;
	}
	map->tab[j] = NULL;                                                                                                                                                   
	map->count_line = count;
	free(tmp);
	return (0);
}