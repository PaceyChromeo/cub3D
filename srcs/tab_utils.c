/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrifa <hkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:14:51 by hkrifa            #+#    #+#             */
/*   Updated: 2021/11/16 11:33:24 by hkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	get_tabnorm2(t_map *map, char **tmp, int index, int j)
{
	while (tmp[index])
	{
		map->tab[j] = get_line(tmp[index], map->line_length);
		free(tmp[index]);
		j++;
		index++;
	}
	map->tab[j] = NULL;
}

int	count_lines(char **tmp, int i)
{
	int	count;

	count = 0;
	while (tmp[i] != NULL)
	{
		count++;
		i++;
	}
	return (count);
}

int	get_max(char **tmp, int i)
{
	int	max;

	max = 0;
	while (tmp[i])
	{
		if ((int)ft_strlen(tmp[i]) > max)
			max = ft_strlen(tmp[i]);
		i++;
	}
	return (max);
}
