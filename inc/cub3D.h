/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrifa <hkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:36:35 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/08 17:55:25 by hkrifa           ###   ########.fr       */
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

# define SCREEN_RES_H 640
# define SCREEN_RES_W 800

typedef struct s_var
{
	int i;
	int j;
	int n;
	int s;
	int e;
	int w;
	
}	t_var;

typedef struct	s_map
{
	
	char	*north_text;
	char	*south_text;
	char	*west_text;
	char	*east_text;
	int		*floor;
	int		*ceiling;
	char	**tab;
	char	*map_name;
	t_var	*var;
	int		pl_x;
	int		pl_y;
	int		line_length;
	int		count_line;
}				t_map;				

/************   COLOR    *********/
int		get_colors(int fd, t_map *map);
/************   FILE    *********/
int		check_file(char *file);
/************   MAP    *********/
t_map	*get_map(int fd, char *av);
/************   MAP ERRORS    *********/
int		check_valid_map(t_map *map);
int		check_valid_walls(t_map *map);
/************   TAB    *********/
int		get_tab(t_map *map);
/************   TEXTURE    *********/
int		get_textures(int fd, t_map *map);
/************   FREE_STUFFS    *********/
void	free_tab(char **tab);
void	free_and_close(t_map *map, int fd);
/************   DEBUG    *********/
int		print_or_count_tab(char **tab, int poc);
void	print_map(t_map *map);
void	print_tab(char **tab);


#endif
