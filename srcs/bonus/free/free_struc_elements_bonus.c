#include "cub3d_bonus.h"

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
	if (texture_color_data.door_texture)
		free(texture_color_data.door_texture);
	if (texture_color_data.s_one_sprite)
		free(texture_color_data.s_one_sprite);
	if (texture_color_data.s_two_sprite)
		free(texture_color_data.s_two_sprite);
	if (texture_color_data.s_three_sprite)
		free(texture_color_data.s_three_sprite);
	if (texture_color_data.s_four_sprite)
		free(texture_color_data.s_four_sprite);
	if (texture_color_data.s_five_sprite)
		free(texture_color_data.s_five_sprite);
	if (texture_color_data.s_six_sprite)
		free(texture_color_data.s_six_sprite);
	if (texture_color_data.s_seven_sprite)
		free(texture_color_data.s_seven_sprite);
}
