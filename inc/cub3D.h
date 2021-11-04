/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:36:35 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/04 13:25:17 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <mlx.h>
# include "../libft/libft.h"

# define PI 3.141593
# define SCREEN_RES_H 640
# define SCREEN_RES_W 800

typedef struct	s_map
{
	char	*north_text;
	char	*south_text;
	char	*west_text;
	char	*east_text;
	int		*floor;
	int		*ceiling;
}				t_map;				

/************   MAP    *********/
t_map	*get_map(int fd);
/************   TEXTURE    *********/
int		get_textures(int fd, t_map *map);
/************   FREE_STUFFS    *********/
void	free_map(t_map *map);

#endif