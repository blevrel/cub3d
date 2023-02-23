#include "cub3d_bonus.h"

bool	check_file_name(char *scene_file)
{
	int	j;

	j = ft_strlen(scene_file) - 4;
	if (ft_strcmp(&scene_file[j], ".cub") != 0)
	{
		ft_print_error("\e[5;31m[ERROR]\e[0m\n");
		ft_print_error("\e[95mFile must have the '.cub' extension\e[0m\n");
		return (false);
	}
	return (true);
}

bool	check_textures_and_colors_elements(t_texture_color_data texture_color_data)
{
	int	i;

	i = 0;
	if (!texture_color_data.no_texture)
		return (false);
	if (!texture_color_data.so_texture)
		return (false);
	if (!texture_color_data.we_texture)
		return (false);
	if (!texture_color_data.ea_texture)
		return (false);
	while (i < 3)
	{
		if (texture_color_data.c_color[i] == -1)
			return (false);
		i++;
	}
	while (i < 3)
	{
		if (texture_color_data.f_color[i] == -1)
			return (false);
		i++;
	}
	return (true);
}

bool	check_valid_scene(char *scene_file, char **mat, t_all *game_struc)
{
	if (!check_file_name(scene_file))
		return (false);
	if (!check_textures_and_colors_elements(game_struc->texture_color_data))
	{
		ft_print_error("\e[5;31m[ERROR]\e[0m\n\e[95mCheck your scene file\e[0m\n");
		return (false);
	}
	if (!check_map_content(mat, &game_struc->map_data))
		return (false);
	if (game_struc->map_data.nb_players != 1)
	{
		ft_print_error("\e[5;31m[ERROR]\e[0m\n\e[95mCheck your scene file\e[0m\n");
		return (false);
	}
	return (true);
}
