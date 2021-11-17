/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:21:17 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/17 17:17:55 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->adr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

double	convert_degre_to_radian(double degre)
{
	double	radian;

	radian = degre * (PI / 180);
	return (radian);
}

double	convert_radian_to_degre(double radian)
{
	double	degre;

	degre = radian * (180 / PI);
	return (degre);
}

double	square_dble(double nb)
{
	return (nb * nb);
}

int	find_color_in_xpm_file(t_map *map, double wall_height, int j)
{
	int	color;

	color = 0;
	if (map->raycast->wall_hit == 0 || map->raycast->wall_hit == 1)
	{
		map->text->tx = fmod(map->raycast->rx
				/ map->minimap->square, 1.0) * 64.0;
	}
	else
		map->text->tx = fmod(map->raycast->ry
				/ map->minimap->square, 1.0) * 64.0;
	map->text->ty = (1.0 - ((double)((SCREEN_H / 2) + wall_height) - j)
			/ (wall_height * 2)) * (double)64.0;
	map->text->index = map->text->tx + (map->text->ty * 64.0);
	if (map->raycast->wall_hit == 0)
		color = map->text[0].adr_text[map->text->index];
	else if (map->raycast->wall_hit == 1)
		color = map->text[1].adr_text[map->text->index];
	else if (map->raycast->wall_hit == 2)
		color = map->text[2].adr_text[map->text->index];
	else if (map->raycast->wall_hit == 3)
		color = map->text[3].adr_text[map->text->index];
	return (color);
}
