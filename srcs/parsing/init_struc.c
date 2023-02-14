#include "cub3d.h"

void	init_struc(t_all *game_struc)
{
	game_struc->map_data.map_width = 0;
	game_struc->map_data.map_height = 0;
	game_struc->map_data.nb_players = 0;
	game_struc->texture_color_data.no_texture = NULL;
	game_struc->texture_color_data.so_texture = NULL;
	game_struc->texture_color_data.we_texture = NULL;
	game_struc->texture_color_data.ea_texture = NULL;
	game_struc->texture_color_data.c_color[0] = -1;
	game_struc->texture_color_data.c_color[1] = -1;
	game_struc->texture_color_data.c_color[2] = -1;
	game_struc->texture_color_data.f_color[0] = -1;
	game_struc->texture_color_data.f_color[1] = -1;
	game_struc->texture_color_data.f_color[2] = -1;
}
