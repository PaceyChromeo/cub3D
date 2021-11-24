/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:59:12 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/24 14:01:53 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	put_texture_in_map(char *texture, char *file, t_map *map, int *text)
{
	if (!ft_strncmp(texture, "NO", 2))
	{
		map->north_text = ft_strdup(file);
		text[0]++;
	}
	else if (!ft_strncmp(texture, "SO", 2))
	{
		map->south_text = ft_strdup(file);
		text[1]++;
	}
	else if (!ft_strncmp(texture, "WE", 2))
	{
		map->west_text = ft_strdup(file);
		text[2]++;
	}
	else if (!ft_strncmp(texture, "EA", 2))
	{
		map->east_text = ft_strdup(file);
		text[3]++;
	}
}

static int	get_texture(char *line, t_map *map, int *text)
{
	char	**split;

	split = ft_split(line, ' ');
	if (print_or_count_tab(split, 0) > 2)
		return (printf("Error: too many file for %s texture\n", split[0]));
	else if (print_or_count_tab(split, 0) == 1)
		return (printf("Error: no file for %s texture\n", split[0]));
	else
	{
		put_texture_in_map(split[0], split[1], map, text);
		if (check_texture_file(split[1]))
			return (1);
	}
	free_tab((void **)split);
	return (0);
}

static int	no_texture(int i)
{
	if (i == 0)
		return (printf("Error: texture NO is missing\n"));
	else if (i == 1)
		return (printf("Error: texture SO is missing\n"));
	else if (i == 2)
		return (printf("Error: texture WE is missing\n"));
	else
		return (printf("Error: texture EA is missing\n"));
}

static int	count_textures(int *texture)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!texture[i])
			return (no_texture(i));
		else if (texture[i] > 1)
		{
			if (i == 0)
				return (printf("Error: too many NO texture: Usage 1\n"));
			else if (i == 1)
				return (printf("Error: too many SO texture: Usage 1\n"));
			else if (i == 2)
				return (printf("Error: too many WE texture: Usage 1\n"));
			else
				return (printf("Error: too many EA texture: Usage 1\n"));
		}
		i++;
	}
	return (0);
}

int	get_textures(int fd, t_map *map)
{
	char	*line;
	int		gnl;
	int		texture[4];

	ft_bzero((int *)texture, 4);
	line = NULL;
	gnl = get_next_line(fd, &line);
	if (gnl == -1)
		return (printf("Error: texture\n"));
	while (gnl > 0)
	{
		if (line && ft_line_is_wrong(line))
			return (1);
		if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
			|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
			if (get_texture(line, map, texture))
				return (1);
		free(line);
		gnl = get_next_line(fd, &line);
	}
	free(line);
	if (count_textures(texture))
		return (1);
	return (0);
}
