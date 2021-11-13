/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuffs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:54:20 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/13 14:55:31 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_and_close(t_map *map, int fd)
{
		free(map->floor);
		free(map->ceiling);
		if (map->tab)
			free_tab(map->tab);
		map->tab = NULL;
		free(map);
		free(map->minimap);
		free(map->player);
		if (fd)
			close(fd);
		if (map->raycast)
			free(map->raycast);
}
