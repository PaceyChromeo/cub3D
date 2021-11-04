/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:59:12 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/04 13:28:27 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	get_texture(t_map *map, char *texture)
{
	(void)map;
	printf("OUI : %s\n", texture);
	return (0);
}

int	get_textures(int fd, t_map *map)
{
	char	**line;
	int		gnl;
	int		i;

	i = 0;
	line = NULL;
	gnl = get_next_line(fd, line);
	if (gnl == -1)
		return (printf("Error: texture\n"));
	while (gnl > 0)
	{
		if (!ft_strncmp(line[i], "NO", 2))
			get_texture(map, "NO");
		i++;
		gnl = get_next_line(fd, line);
	}
	return (0);
}