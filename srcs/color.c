/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:38:13 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/15 11:11:07 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	check_rgb(char **rgb, int i, char element, size_t x)
{
	while (rgb[i] && i < 3)
	{
		x = 0;
		while (x < ft_strlen(rgb[i]))
		{
			while (x < ft_strlen(rgb[i]) && rgb[i][x] == ' ')
				x++;
			while (x < ft_strlen(rgb[i]) && ft_isdigit(rgb[i][x]))
				x++;
			while (x < ft_strlen(rgb[i]) && rgb[i][x] == ' ')
				x++;
			if (x != ft_strlen(rgb[i]))
			{
				if (i == 0)
					return (printf("Error: 1st arg of %c is wrong\n", element));
				else if (i == 1)
					return (printf("Error: 2nd arg of %c is wrong\n", element));
				else
					return (printf("Error: 3rd arg of %c is wrong\n", element));
			}
			x++;
		}
		i++;
	}
	return (0);
}

static int	put_color_in_map(char element, char **rgb, t_map *map, int *color)
{
	if (check_rgb(rgb, 0, element, 0))
		return (1);
	if (element == 'F')
	{
		map->i = -1;
		while (++map->i < 3)
		{
			map->floor[map->i] = ft_atoi(rgb[map->i]);
			if (map->floor[map->i] < 0 || map->floor[map->i] > 255)
				return (printf("Error: floor color must be under 256\n"));
		}
		color[0]++;
	}
	else
	{
		map->i = -1;
		while (++map->i < 3)
		{
			map->ceiling[map->i] = ft_atoi(rgb[map->i]);
			if (map->ceiling[map->i] < 0 || map->ceiling[map->i] > 255)
				return (printf("Error: ceiling color must be under 256\n"));
		}
		color[1]++;
	}
	return (0);
}

static int	get_color(char *line, t_map *map, int *color)
{
	char	**split;
	char	*trim;
	int		i;

	trim = ft_calloc(sizeof(char), ft_strlen(line));
	if (!trim)
		return (1);
	i = 1;
	while (line[++i])
		trim[i - 2] = line[i];
	trim[i - 2] = '\0';
	split = ft_split(trim, ',');
	if (print_or_count_tab(split, 0) > 3)
		return (printf("Error: too many color for %c\n", line[0]));
	else if (print_or_count_tab(split, 0) == 1)
		return (printf("Error: no color or only one color for %c\n", line[0]));
	else if (print_or_count_tab(split, 0) == 2)
		return (printf("Error: one color is missing for %c\n", line[0]));
	else
		put_color_in_map(line[0], split, map, color);
	free(trim);
	free_tab(split);
	return (0);
}

static int	count_color(int *color)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (color[i] == 0)
		{
			if (i == 0)
				return (printf("Error: F color is missing\n"));
			else
				return (printf("Error: C color is missing\n"));
		}
		else if (color[i] > 1)
		{
			if (i == 0)
				return (printf("Error: too many F color: Usage 1\n"));
			else
				return (printf("Error: too many C color: Usage 1\n"));
		}
		i++;
	}
	return (0);
}

int	get_colors(int fd, t_map *map)
{
	char	*line;
	int		gnl;
	int		color[2];

	ft_bzero((int *)color, 2);
	close(fd);
	fd = open(map->map_name, O_RDONLY);
	line = NULL;
	gnl = get_next_line(fd, &line);
	if (gnl == -1)
		return (printf("Error: color\n"));
	while (gnl > 0)
	{
		if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		{
			if (get_color(line, map, color))
				return (1);
		}
		free(line);
		gnl = get_next_line(fd, &line);
	}
	free(line);
	if (count_color(color))
		return (1);
	return (0);
}
