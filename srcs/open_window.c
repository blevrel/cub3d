/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:53:49 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/09 17:54:34 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

bool	load_textures(t_texture_data texture_data
			, t_texture_images_data *texture_images_data, t_window window)
{
	int	x;

	texture_images_data->no_image = mlx_xpm_file_to_image(window.mlx,
			texture_data.no_texture, &x, &x);
	if (!texture_images_data->no_image)
		return (false);
	texture_images_data->so_image = mlx_xpm_file_to_image(window.mlx,
			texture_data.so_texture, &x, &x);
	if (!texture_images_data->so_image)
		return (false);
	texture_images_data->we_image = mlx_xpm_file_to_image(window.mlx,
			texture_data.we_texture, &x, &x);
	if (!texture_images_data->we_image)
		return (false);
	texture_images_data->ea_image = mlx_xpm_file_to_image(window.mlx,
			texture_data.ea_texture, &x, &x);
	if (!texture_images_data->ea_image)
		return (false);
	return (true);
}

void	*open_window(t_window window, t_texture_data texture_data
			, t_texture_images_data *texture_images_data)
{
	if (load_textures(texture_data, texture_images_data, window) == false)
	{
		ft_print_error("\e[5;31m[ERROR]\e[0m\n\e[95mTexture not found\e[0m\n");
		return (NULL);
	}
	window.win_ptr = mlx_new_window(window.mlx, WIN_WIDTH,
			WIN_HEIGHT, "cub3D");
	return (window.win_ptr);
}
