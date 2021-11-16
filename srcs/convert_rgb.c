/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrifa <hkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:53:43 by hkrifa            #+#    #+#             */
/*   Updated: 2021/11/16 10:30:14 by hkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

unsigned int	convert_rgb_floor(t_map *map)
{
	unsigned int result;

	result = (map->floor[0] << 16 | map->floor[1] << 8 | map->floor[2]);
	return (result);
}

unsigned int	convert_rgb_ceiling(t_map *map)
{
	unsigned int result;

	result = (map->ceiling[0] << 16 | map->ceiling[1] << 8 | map->ceiling[2]);
	return (result);
}