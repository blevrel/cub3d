/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:16:24 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/10 13:08:15 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

char	**get_parsed_mat(char *scene_file, t_all *game_struc, int fd)
{
	char	**mat;
	char	**mat_with_border;

	mat = alloc_mat(scene_file, fd, &game_struc->map_data);
	if (!mat)
		return (NULL);
	mat_with_border = add_border(mat, &game_struc->map_data);
	if (!mat_with_border)
	{
		free_double_tab(mat);
		return (NULL);
	}
	if (close(fd) == -1)
	{
		free_double_tab(mat_with_border);
		return (NULL);
	}
	if (!check_valid_scene(scene_file, mat_with_border, game_struc))
	{
		free_double_tab(mat_with_border);
		return (NULL);
	}
	return (mat_with_border);
}

char	**start_parsing(char *scene_file, t_all *game_struc)
{
	int		i;
	int		fd;
	char	**mat;

	i = 0;
	fd = init_textures_and_colors(&game_struc->color_data,
			&game_struc->texture_data, scene_file);
	if (fd == -1)
	{
		ft_print_error("\e[5;31m[ERROR]\e[0m\n\e[95mOpen failed\e[0m\n");
		free_struc_elements(game_struc->texture_data);
		return (NULL);
	}
	mat = get_parsed_mat(scene_file, game_struc, fd);
	if (!mat)
	{
		free_struc_elements(game_struc->texture_data);
		return (NULL);
	}
	return (mat);
}

int	main(int argc, char **argv)
{
	char	**mat;
	t_all	game_struc;

	if (argc != 2)
	{
		ft_print_error("Invalid args. Usage: %s *scene_file*.cub\n", argv[0]);
		return (-1);
	}
	init_struc(&game_struc);
	mat = start_parsing(argv[1], &game_struc);
	if (!mat)
		return (-2);
	game_struc.window.mlx = mlx_init();
	game_struc.window.win_ptr = open_window(game_struc.window,
			game_struc.texture_data, &game_struc.images_data);
	display_minimap(mat, game_struc.window, game_struc.map_data);
	mlx_loop(game_struc.window.mlx);
	free_double_tab(mat);
	free_struc_elements(game_struc.texture_data);
	mlx_destroy_display(game_struc.window.mlx);
	free(game_struc.window.mlx);
	return (0);
}
