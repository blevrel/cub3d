#include "cub3d_bonus.h"

void	init_struc(t_all *game_struc)
{
	game_struc->map_data.map_width = 0;
	game_struc->map_data.map_height = 0;
	game_struc->map_data.nb_players = 0;
	game_struc->texture_color_data.no_texture = NULL;
	game_struc->texture_color_data.so_texture = NULL;
	game_struc->texture_color_data.we_texture = NULL;
	game_struc->texture_color_data.ea_texture = NULL;
	game_struc->texture_color_data.s_one_sprite = NULL;
	game_struc->texture_color_data.s_two_sprite = NULL;
	game_struc->texture_color_data.s_three_sprite = NULL;
	game_struc->texture_color_data.s_four_sprite = NULL;
	game_struc->texture_color_data.s_five_sprite = NULL;
	game_struc->texture_color_data.s_six_sprite = NULL;
	game_struc->texture_color_data.s_seven_sprite = NULL;
	game_struc->texture_color_data.c_color[0] = -1;
	game_struc->texture_color_data.c_color[1] = -1;
	game_struc->texture_color_data.c_color[2] = -1;
	game_struc->texture_color_data.f_color[0] = -1;
	game_struc->texture_color_data.f_color[1] = -1;
	game_struc->texture_color_data.f_color[2] = -1;
}

void	init_images(t_render_images *render_images, t_window window)
{
	render_images->minimap_render.img
		= mlx_new_image(window.mlx, MINI_WIDTH + 1, MINI_HEIGHT + 1);
	render_images->minimap_render.addr
		= mlx_get_data_addr(render_images->minimap_render.img,
			&render_images->minimap_render.bits_per_pixel,
			&render_images->minimap_render.line_length,
			&render_images->minimap_render.endian);
	render_images->window_render.img
		= mlx_new_image(window.mlx, WIN_WIDTH, WIN_HEIGHT);
	render_images->window_render.addr
		= mlx_get_data_addr(render_images->window_render.img,
			&render_images->window_render.bits_per_pixel,
			&render_images->window_render.line_length,
			&render_images->window_render.endian);
}
