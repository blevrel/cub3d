#include "cub3d.h"

void	free_struc_elements(t_texture_data texture_data)
{
	if (texture_data.no_texture)
		free(texture_data.no_texture);
	if (texture_data.so_texture)
		free(texture_data.so_texture);
	if (texture_data.we_texture)
		free(texture_data.we_texture);
	if (texture_data.ea_texture)
		free(texture_data.ea_texture);
}
