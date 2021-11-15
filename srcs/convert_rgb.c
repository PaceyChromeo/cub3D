/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrifa <hkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:53:43 by hkrifa            #+#    #+#             */
/*   Updated: 2021/11/15 19:51:15 by hkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static unsigned int	convert_au_cube(int nb)
{
	return (nb * nb * nb);
}

static unsigned int	convert_squared(int nb)
{
	return (nb * nb);
}

unsigned int	convert_rgb_floor(t_map *map)
{
	
	return (convert_au_cube(map->floor[0])
		+ convert_squared(map->floor[1] + map->floor[2]));
}

unsigned int	convert_rgb_ceiling(t_map *map)
{
	return (convert_au_cube(map->ceiling[0])
		+ convert_squared(map->ceiling[1] + map->ceiling[2]));
}