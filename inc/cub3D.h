/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:36:35 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/13 14:55:59 by pjacob           ###   ########.fr       */
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

# define SCREEN_H 800
# define SCREEN_W 1200
# define ESC 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define L_KEY 123
# define R_KEY 124
# define PI 3.141593
# define BLACK 0x000000
# define GREY 0x808080
# define SILVER 0xC0C0C0
# define WHITE 0xFFFFFF
# define NAVY 0x000080
# define BLUE 0x0000FF
# define TEAL 0x008080
# define AQUA 0x00FFFF
# define GREEN 0x008000
# define LIME 0x00FF00
# define OLIVE 0x808000
# define YELLOW 0xFFFF00
# define MAROON 0x800000
# define RED 0xFF0000
# define PURPLE 0x800080
# define FUCHSIA 0xFF00FF
# define DARK_BLUE 0x3e6358
# define LIGHT_CYAN 0x6eccc4

typedef struct	s_raycast
{
	double	ra;
	double	rx;
	double	ry;
	int		coord_x;
	int		coord_y;
}				t_raycast;


typedef struct	s_img
{
	void	*img_ptr;
	char	*adr;
	int		line_length;
	int		bpp;
	int		endian;
	double	line;
	double	column;
	double		square;
}				t_img;

typedef struct s_var
{
	int i;
	int j;
	int n;
	int s;
	int e;
	int w;
	
}	t_var;

typedef struct	s_player
{
	double	pos_x;
	double	pos_y;
	double	delta_x;
	double	delta_y;
	double	angle;
}				t_player;

typedef struct	s_map
{
	void		*mlx_ptr;
	void		*mlx_win;
	char		*north_text;
	char		*south_text;
	char		*west_text;
	char		*east_text;
	int			*floor;
	int			*ceiling;
	char		**tab;
	char		*map_name;
	int			line_length;
	int			max_len;
	int			count_line;
	int			pl_x;
	int			pl_y;
	char		pl_view;
	t_var		*var;
	t_img		*minimap;
	t_player	*player;
	t_raycast	*raycast;
}				t_map;				

/************   COLOR    *********/
int		get_colors(int fd, t_map *map);
/************   DEBUG    *********/
int		print_or_count_tab(char **tab, int poc);
void	print_map(t_map *map);
/************   DRAW    *********/
void	draw_square(t_map *map, int x, int y, int color);
void	draw_grid(t_map *map);
void	draw_player(t_map *map, double x, double y, int color);
void	draw_player_line(t_map *map, double x, double y, int color);
void	draw_line(t_map *map, double x, double y, int color);
/************   FILE    *********/
int		check_file(char *file);
int		check_texture_file(char *file);
/************   FREE_STUFFS    *********/
void	free_tab(char **tab);
void	free_and_close(t_map *map, int fd);
/************   KEY    *********/
void	deal_up_key(t_map *map);
void	deal_left_key(t_map *map);
void	deal_down_key(t_map *map);
void	deal_right_key(t_map *map);
void	deal_left_arrow(t_map *map);
void	deal_right_arrow(t_map *map);
/************   LOOP    *********/
int		img_loop(t_map *map);
/************   MAP    *********/
t_map	*get_map(int fd, char *av);
/************   MAP ERRORS    *********/
int		check_valid_map(t_map *map);
int		check_valid_walls(t_map *map);
int 	check_valid_spaces(t_map *map);
/************   MINIMAP    *********/
int		get_minimap(t_map *map);
void	display_minimap(t_map *map);
/************   MLX_HOOK    *********/
int		close_win(void);
int		deal_keys(int keycode, t_map *map);
/************   PLAYER    *********/
int		get_player(t_map *map);
/************   RAYCASTING    *********/
void	keep_closest_point(t_raycast *raycast, double next_x, double next_y);
void	draw_rays(t_map *map);
void	raycasting(t_map *map);
/************   TAB    *********/
int		get_tab(t_map *map);
int		count_lines(char **tmp, int i);
int		get_max(char **tmp, int i);
/************   TEXTURE    *********/
int		get_textures(int fd, t_map *map);
/************   UTILS    *********/
void	ft_put_pixel(t_img *minimap, int x, int y, int color);
double	convert_degre_to_radian(double degre);
double	convert_radian_to_degre(double radian);
/************   WALL    *********/
void	check_walls(t_map *map, t_raycast *raycast);

#endif