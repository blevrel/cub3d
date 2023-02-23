#include "cub3d_bonus.h"

bool	load_textures(t_texture_color_data texture_color_data
			, t_render_data *render_data, t_window window)
{
	int	x;

	render_data->no_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.no_texture, &x, &x);
	if (!render_data->no_image)
		return (false);
	render_data->so_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.so_texture, &x, &x);
	if (!render_data->so_image)
		return (false);
	render_data->we_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.we_texture, &x, &x);
	if (!render_data->we_image)
		return (false);
	render_data->ea_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.ea_texture, &x, &x);
	if (!render_data->ea_image)
		return (false);
	return (true);
}

void	*open_window(t_window window, t_texture_color_data texture_color_data
			, t_render_data *render_data)
{
	if (load_textures(texture_color_data, render_data, window) == false)
	{
		ft_print_error("\e[5;31m[ERROR]\e[0m\n\e[95mTexture not found\e[0m\n");
		return (NULL);
	}
	window.win_ptr = mlx_new_window(window.mlx, WIN_WIDTH,
			WIN_HEIGHT, "cub3D");
	return (window.win_ptr);
}
