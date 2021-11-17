/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:53:43 by hkrifa            #+#    #+#             */
/*   Updated: 2021/11/17 17:14:31 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

unsigned int	convert_rgb_floor(t_map *map)
{
	unsigned int	result;

	result = (map->floor[0] << 16 | map->floor[1] << 8 | map->floor[2]);
	return (result);
}

unsigned int	convert_rgb_ceiling(t_map *map)
{
	unsigned int	result;

	result = (map->ceiling[0] << 16 | map->ceiling[1] << 8 | map->ceiling[2]);
	return (result);
}

int	init_texture(t_map *map)
{
	map->text[0].img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->north_text, &map->text[0].width, &map->text[0].height);
	if (map->text[0].img_ptr == NULL)
		return (printf("Error : Cannot open NO"));
	map->text[0].adr_text = (int *)mlx_get_data_addr(map->text[0].img_ptr,
			&map->text[0].bpp, &map->text[0].line_length, &map->text[0].endian);
	map->text[1].img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->south_text, &map->text[1].width, &map->text[1].height);
	if (map->text[0].img_ptr == NULL)
		return (printf("Error : Cannot open SO"));
	map->text[1].adr_text = (int *)mlx_get_data_addr(map->text[1].img_ptr,
			&map->text[1].bpp, &map->text[1].line_length, &map->text[1].endian);
	map->text[2].img_ptr = mlx_xpm_file_to_image(map->mlx_ptr, map->east_text,
			&map->text[2].width, &map->text[2].height);
	if (map->text[0].img_ptr == NULL)
		return (printf("Error : Cannot open EA"));
	map->text[2].adr_text = (int *)mlx_get_data_addr(map->text[2].img_ptr,
			&map->text[2].bpp, &map->text[2].line_length, &map->text[2].endian);
	map->text[3].img_ptr = mlx_xpm_file_to_image(map->mlx_ptr, map->west_text,
			&map->text[3].width, &map->text[3].height);
	if (map->text[0].img_ptr == NULL)
		return (printf("Error : Cannot open WE"));
	map->text[3].adr_text = (int *)mlx_get_data_addr(map->text[3].img_ptr,
			&map->text[3].bpp, &map->text[3].line_length, &map->text[3].endian);
	return (0);
}
