/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:36:35 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/18 12:05:17 by pjacob           ###   ########.fr       */
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

# define SQUARE 64
# define SCREEN_H 400
# define SCREEN_W 640
# define ESC 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define L_KEY 123
# define R_KEY 124
# define PI 3.141592653
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

typedef struct s_raycast
{
	double	ra;
	double	rx;
	double	ry;
	int		coord_x;
	int		coord_y;
	int		wall_hit;
}				t_raycast;

typedef struct s_text
{
	void			*img_ptr;
	int				*adr_text;
	int				bpp;
	int				line_length;
	int				endian;
	int				width;
	int				height;
	int				tx;
	int				ty;
	int				index;	
}				t_text;

typedef struct s_img
{
	void			*img_ptr;
	char			*adr;
	int				line_length;
	int				bpp;
	int				endian;
	double			line;
	double			column;
	double			square;
	int				width;
	int				height;
	unsigned int	fl;
	unsigned int	ceil;
}				t_img;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	delta_x;
	double	delta_y;
	double	angle;
}				t_player;

typedef struct s_map
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
	int			count_line;
	int			pl_x;
	int			pl_y;
	char		pl_view;
	int			i;
	int			fd;
	double		dist;
	double		dpp;
	t_img		*minimap;
	t_player	*player;
	t_raycast	*raycast;
	t_img		*cub;
	t_text		text[4];
}				t_map;				

/************   COLOR    *********/
int				get_colors(int fd, t_map *map);
/************   CUB    *********/
int				cub_init(t_map *map);
/************   CONVERT_RGB    *********/
unsigned int	convert_rgb_ceiling(t_map *map);
unsigned int	convert_rgb_floor(t_map *map);
int				init_texture(t_map *map);
/************   DEBUG    *********/
int				print_or_count_tab(char **tab, int poc);
void			print_map(t_map *map);
/************   DRAW    *********/
void			draw_square(t_map *map, int x, int y, int color);
void			draw_grid(t_map *map);
void			draw_player(t_map *map, double x, double y, int color);
void			draw_player_line(t_map *map, double x, double y, int color);
void			draw_line(t_map *map, double x, double y, int color);
/************   DISTANCE   *********/
void			draw_walls(t_map *map, int i);
/************   FILE    *********/
int				check_file(char *file);
int				check_texture_file(char *file);
/************   FREE_STUFFS    *********/
void			free_tab(void **tab);
void			free_and_close(t_map *map, int fd);
/************   KEY    *********/
void			deal_up_key(t_map *map);
void			deal_left_key(t_map *map);
void			deal_down_key(t_map *map);
void			deal_right_key(t_map *map);
void			deal_left_arrow(t_map *map);
void			deal_right_arrow(t_map *map);
/************   LOOP    *********/
int				img_loop(t_map *map);
/************   MAP    *********/
t_map			*get_map(int fd, char *av);
/************   MAP ERRORS    *********/
char			*get_line(char *line, int max);
int				check_valid_map(t_map *map);
int				check_valid_walls(t_map *map);
int				check_valid_spaces(t_map *map);
/************   MINIMAP    *********/
int				get_minimap(t_map *map);
void			display_minimap(t_map *map, int i, int y);
/************   MLX_HOOK    *********/
int				close_win(t_map *map);
int				deal_keys(int keycode, t_map *map);
/************   PLAYER    *********/
int				get_player(t_map *map);
/************   RAYCASTING    *********/
void			keep_closest_point(t_raycast *raycast,
					double next_x, double next_y);
void			draw_rays(t_map *map);
void			raycasting(t_map *map);
/************   TAB    *********/
int				get_tab(t_map *map, int j, int index, int ok);
void			get_tabnorm2(t_map *map, char **tmp, int index, int j);
int				count_lines(char **tmp, int i);
int				get_max(char **tmp, int i);
/************   TEXTURE    *********/
int				get_textures(int fd, t_map *map);
/************   UTILS    *********/
void			ft_put_pixel(t_img *minimap, int x, int y, int color);
double			convert_degre_to_radian(double degre);
double			convert_radian_to_degre(double radian);
double			square_dble(double nb);
int				find_color_in_xpm_file(t_map *map, double wall_height, int j);
/************   WALL    *********/
void			check_walls(t_map *map, t_raycast *raycast);

#endif