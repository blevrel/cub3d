#include "cub3d.h"

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
	if (!render_data->no_image || !render_data->so_image
		|| !render_data->we_image ||!render_data->ea_image)
	{
		ft_print_error("\e[5;31m[ERROR]\e[0m\n\e[95mTexture not found\e[0m\n");
		return (false);
	}
	return (true);
}
