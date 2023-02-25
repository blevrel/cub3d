#include "cub3d_bonus.h"

static bool	load_sprites(t_texture_color_data texture_color_data,
			t_render_data *render_data, t_window window)
{
	int	x;

	render_data->s_one_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.s_one_sprite, &x,
			&x);
	render_data->s_two_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.s_two_sprite, &x,
			&x);
	render_data->s_three_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.s_three_sprite, &x,
			&x);
	render_data->s_four_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.s_four_sprite, &x,
			&x);
	render_data->s_five_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.s_four_sprite, &x,
			&x);
	render_data->s_six_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.s_six_sprite, &x,
			&x);
	render_data->s_seven_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.s_seven_sprite, &x,
			&x);

	if (!render_data->s_one_image || !render_data->s_two_image
		|| !render_data->s_three_image || !render_data->s_four_image
		|| !render_data->s_five_image || !render_data->s_six_image
		|| !render_data->s_seven_image)
		return (false);
	return (true);
}

bool	load_textures(t_texture_color_data texture_color_data,
			t_render_data *render_data, t_window window)
{
	render_data->no_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.no_texture, &render_data->width,
			&render_data->height);
	render_data->so_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.so_texture, &render_data->width,
			&render_data->height);
	render_data->we_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.we_texture, &render_data->width,
			&render_data->height);
	render_data->ea_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.ea_texture, &render_data->width,
			&render_data->height);
	render_data->door_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.door_texture, &render_data->width,
			&render_data->height);
	if (!load_sprites(texture_color_data, render_data, window)
		|| !render_data->no_image || !render_data->so_image
		|| !render_data->we_image ||!render_data->ea_image
		|| !render_data->door_image)
	{
		ft_print_error("\e[5;31m[ERROR]\e[0m\n\e[95mTexture not found\e[0m\n");
		return (false);
	}
	return (true);
}
