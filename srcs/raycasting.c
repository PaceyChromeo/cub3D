/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:21:30 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/11 12:38:25 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static t_raycast	*init_raycasting(void)
{
	t_raycast	*raycast;

	raycast = ft_calloc(sizeof(t_raycast), 1);
	if (!raycast)
		return (NULL);
	raycast->mx = 0;	
	raycast->my = 0;	
	raycast->mp = 0;	
	raycast->rx = 0;	
	raycast->ry = 0;	
	raycast->ra = 0;	
	raycast->xo = 0;	
	raycast->yo = 0;
	return (raycast);
}

static void	check_horizontal_line(t_map *map, t_raycast *raycast)
{
	int	dof;
	double	aTan;

	dof = 0;
	aTan = -1 / tan(raycast->ra);
	if (raycast->ra > PI)
	{
		raycast->ry = (((int)map->player->pos_y >> 6) << 6) - 0.0001;
		raycast->rx = (map->player->pos_y - raycast->ry) * aTan + map->player->pos_x;
		raycast->yo -= map->minimap->square;
		raycast->xo -= raycast->yo * aTan; 
	}
	if (raycast->ra < PI)
	{
		raycast->ry = (((int)map->player->pos_y >> 6) << 6) + map->minimap->square;
		raycast->rx = (map->player->pos_y - raycast->ry) * aTan + map->player->pos_x;
		raycast->yo -= map->minimap->square;
		raycast->xo -= raycast->yo * aTan; 
	}
	if (raycast->ra == 0 || raycast->ra == PI)
	{
		raycast->rx = map->player->pos_x;
		raycast->ry = map->player->pos_y;
		dof = 8;
	}
	while (dof < 8)
	{
		
	}
}

void	raycasting(t_map *map)
{
	t_raycast	*raycast;
	int			r;

	r = 0;
	raycast = init_raycasting();
	if (!raycast)
		return ;
	raycast->ra = map->player->angle;
	while (r < 1)
	{
		check_horizontal_line(map, raycast);
		r++;	
	}
}