/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacey <pacey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:28:36 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/06 22:55:09 by pacey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	print_or_count_tab(char **tab, int poc)
{
	int	i;

	i = 0;
	if (poc)
		printf("------------BEGIN OF TAB-------------\n");
	while(tab[i])
	{
		if (poc)
			printf("%s\n", tab[i]);
		i++;
	}
	if (poc)
	{
		printf("------------  i : %d  -------------\n", i);
		printf("------------END OF TAB-------------\n");
	}
	return (i);
}

void	print_map(t_map *map)
{
	int	i;

	printf("north_text : %s\n", map->north_text);
	printf("south_text : %s\n", map->south_text);
	printf("west_text : %s\n", map->west_text);
	printf("east_text : %s\n", map->east_text);
	printf("floor : ");
	i = 0;
	while (i < 3)
	{
		printf("%d ", map->floor[i]);
		if (i < 2)
		printf("| ");
		if (i == 2)
		printf("\n");
		i++;
	}
	printf("ceiling : ");
	i = 0;
	while (i < 3)
	{
		printf("%d ", map->ceiling[i]);
		if (i < 2)
		printf("| ");
		if (i == 2)
		printf("\n");
		i++;
	}
	if (map->tab)
		print_or_count_tab(map->tab, 1);
	printf("map_name : %s\n", map->map_name);
}

void	print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}