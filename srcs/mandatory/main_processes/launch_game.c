#include "cub3d.h"

void	launch_game(t_all *game_struct)
{
	init_data(game_struct);
	cast_rays(game_struct);
	display_minimap(*game_struct);
	mlx_hook(game_struct->window.win_ptr, DestroyNotify, StructureNotifyMask,
		destroy, game_struct);
	mlx_hook(game_struct->window.win_ptr, KeyPress, KeyPressMask,
		game_management, game_struct);
}
