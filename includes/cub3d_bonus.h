#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# define PLAYER 1
# define WALL 2
# define FLOOR 3
# define SPACE 4
# define BORDER 5
# define NORTH 6
# define SOUTH 7
# define WEST 8
# define EAST 9
# define DOOR 10
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define SQ_SIZE 32
# define WALL_SIZE 250 
# define PLANE 0.66
# define MINI_WIDTH 193
# define MINI_HEIGHT 193
# define MINI_POS 20
# define MINI_PLAYER_SIZE 11
# define MINI_VISION 3
# define BORDER_COLOR 0x854442
# define VOID_COLOR 0x800000
# define WALL_COLOR 0x4b3832
# define FLOOR_COLOR 0xfff4e6
# define C_DOOR_COLOR 0x011f4b
# define O_DOOR_COLOR 0x005b96
# define SPRITE_HEIGHT 170
# define SPRITE_WIDTH 70
# define PLAYER_COLOR 0xbe9b7b
# define MOVESPEED 2
# define KEY_ROTSPEED 10
# define MOUSE_ROTSPEED 1
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include "structures_bonus.h"
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"

bool			check_valid_scene(char *scene_file, char **mat, t_all *game_struc);
char			**add_border(char **mat, t_map_data *map_data);
char			**alloc_mat(char *scene_file, int fd, t_map_data *map_data);
char			**fill_mat(char *line, int fd, char **mat, t_map_data *map_data);
bool			check_map_content(char **mat, t_map_data *map_data);
void			init_struc(t_all *game_struc);
void			init_images(t_render_images *render_images, t_window window);
int				get_map_height(int fd);
int				get_map_width(char **mat);
int				init_textures_and_colors(t_texture_color_data *texture_color_data,
					char *scene_file);
int				skip_textures_and_colors(char *scene_file);
void			free_struc_elements(t_texture_color_data texture_color_data);
void			fill_texture_elements(t_texture_color_data *texture_color_data,
					char **line);
int				get_color_elements(t_texture_color_data *texture_color_data,
					char **line, int trigger);
int				convert_rgb_to_hexa(int *color);
void			display_minimap(t_all game_struct);
void			cast_rays(t_all *game_struct);
t_img_data		draw_vertical_line(t_img_data render_img, t_render_data render_data,
					int x, float distance);
void			my_pixel_put(t_img_data *data, float x, float y, int color);
t_img_data		draw_border(t_img_data img_data);
t_triangle		get_triangle_coords(float angle);
void			launch_game(t_all *game_struct);
t_player		move(int keycode, t_player pos, char **mat);
int				check_collision_x(t_player pos, char **mat, char *oper);
int				check_collision_y(t_player pos, char **mat, char *oper);
void			put_vertical_line(float distance, int pxl_horizontal,
					t_img_data render_img, t_render_data render_data);
char			**start_parsing(char *scene_file, t_all *game_struc);
void			init_data(t_all *game_struct);
t_raycast_dir	init_raycast_dir(t_all *game_struct);
t_raycast_dist	get_raycast_dist(t_raycast_dir directions, t_player player);
int				game_management(int keycode, t_all *game_struct);
int				movement_management(int keycode, t_all *game_struct);
int				door_management(t_all *game_struct);
t_raycast_dir	get_new_dir_and_plane(t_raycast_dir direction,
					float angle);
void			get_side_of_wall_hit(t_render_data *render_data,
					t_raycast_dist distance, t_raycast_dir direction);
float			get_ray_hit_coords(t_raycast_dist distance,
					t_player player, float perp_wall_dist,
					t_raycast_dir direction);
int				get_texture_coords(t_render_data render_data, t_raycast_dist distance,
					t_raycast_dir direction);
bool			load_textures(t_texture_color_data texture_color_data,
					t_render_data *render_data, t_window window);
void	draw_sword(t_render_data render_data, t_window window,
			t_render_images render_images);

#endif
