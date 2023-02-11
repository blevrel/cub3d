/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:37:15 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/11 15:41:22 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H
# define PLAYER 1
# define WALL 2
# define FLOOR 3
# define SPACE 4
# define BORDER 5
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define SQ_SIZE 32
# define MINI_WIDTH 193
# define MINI_HEIGHT 193
# define MINI_POS 20
# define MINI_PLAYER_SIZE 12
# define MINI_VISION 3
# define BORDER_COLOR 0x854442
# define WALL_COLOR 0x4b3832
# define FLOOR_COLOR 0xfff4e6
# define PLAYER_COLOR 0xbe9b7b
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "structures.h"
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"

bool		check_valid_scene(char *scene_file, char **mat, t_all *game_struc);
char		**add_border(char **mat, t_map_data *map_data);
char		**alloc_mat(char *scene_file, int fd, t_map_data *map_data);
char		**fill_mat(char *line, int fd, char **mat, t_map_data *map_data);
bool		check_map_content(char **mat, t_map_data *map_data);
void		init_struc(t_all *game_struc);
int			get_map_height(int fd);
int			get_map_width(char **mat);
int			init_textures_and_colors(t_color_data *color_data,
				t_texture_data *texture_data, char *scene_file);
int			skip_textures_and_colors(char *scene_file);
void		free_struc_elements(t_texture_data texture_data);
void		fill_texture_elements(t_texture_data *texture_data, char **line);
int			get_color_elements(t_color_data *color_data, char **line, int trigger);
void		*open_window(t_window window, t_texture_data texture_data,
				t_texture_images_data *images_data);
void		display_minimap(char **mat, /*t_player player,*/ t_window window,
				t_map_data map_data);
void		my_pixel_put(t_img_data *data, int x, int y, int color);
t_img_data	draw_border(t_img_data img_data);

#endif
