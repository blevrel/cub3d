#include "cub3d.h"

void	free_struc_elements(t_texture_color_data texture_color_data)
{
	if (texture_color_data.no_texture)
		free(texture_color_data.no_texture);
	if (texture_color_data.so_texture)
		free(texture_color_data.so_texture);
	if (texture_color_data.we_texture)
		free(texture_color_data.we_texture);
	if (texture_color_data.ea_texture)
		free(texture_color_data.ea_texture);
}
