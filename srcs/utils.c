/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:21:17 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/11 10:42:45 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	ft_put_pixel(t_img *minimap, int x, int y, int color)
{
	char	*dst;

	dst = minimap->adr + (y * minimap->line_length + x * (minimap->bpp / 8));
	*(unsigned int *)dst = color;
}

double	convert_degre_to_radian(double degre)
{
	double radian;

	radian = degre * (PI / 180);
	return (radian);
}

double	convert_radian_to_degre(double radian)
{
	double degre;

	degre = radian * (180 / PI);
	return (degre);	
}
