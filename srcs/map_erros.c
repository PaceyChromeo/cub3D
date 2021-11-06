/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_erros.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrifa <hkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:25:57 by hkrifa            #+#    #+#             */
/*   Updated: 2021/11/05 15:31:51 by hkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	check_map_errornorm(int i, int j, char **tab, t_map *map)
{
	if (i == 0 || j == 0 || i == map->count_line - 1
		|| j == map->line_length - 1)
	{
		if (tab[i][j] != '1' || tab[i][j] != ' ')
		{
			ft_putendl_fd("Error : The map is not surrounded by walls",
				STDERR_FILENO);
			free_tab(tab);
			exit (EXIT_FAILURE);
		}
	}
	if ((i > 0 && i < map->count_line - 1)
		&& (j > 0 && j < map->line_length - 1))
	{
		if (tab[i][j] != '0' && tab[i][j] != '1' && tab[i][j] != 'N'
			&& tab[i][j] != 'S' && tab[i][j] != 'E' && tab[i][j] != 'W')
		{
			ft_putendl_fd("Error : Invalid character found", STDERR_FILENO);
			free_tab(tab);
			exit (EXIT_FAILURE);
		}
	}
}

int	check_map_error(char **tab, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (j < map->line_length)
		{
			ft_check_map_errornorm(i, j, tab, map);
			j++;
		}
		i++;
	}
	return (1);
}