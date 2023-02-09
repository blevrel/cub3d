/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:53:49 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/07 17:02:40 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

bool	load_textures(t_texture_data texture_data, t_images_data *images_data
			,t_window window)
{
	int	x;

	images_data->no_image = mlx_xpm_file_to_image(window.mlx,
			texture_data.no_texture, &x, &x);
	if (!images_data->no_image)
		return (false);
	images_data->so_image = mlx_xpm_file_to_image(window.mlx,
		texture_data.so_texture, &x, &x);
	if (!images_data->so_image)
		return (false);
	images_data->we_image = mlx_xpm_file_to_image(window.mlx,
			texture_data.we_texture, &x, &x);
	if (!images_data->we_image)
		return (false);
	images_data->ea_image = mlx_xpm_file_to_image(window.mlx,
			texture_data.ea_texture, &x, &x);
	if (!images_data->ea_image)
		return (false);
	return (true);
}

void	*open_window(t_window window, t_texture_data texture_data
			,t_images_data *images_data)
{
	if (load_textures(texture_data, images_data, window) == false)
	{
		ft_print_error("\e[5;31m[ERROR]\e[0m\n\e[95mTexture not found\e[0m\n");
		return (NULL);
	}
	window.win_ptr = mlx_new_window(window.mlx, WIDTH
			, HEIGHT, "cub3D");
	return (window.win_ptr);
}
