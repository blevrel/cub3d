#include "cub3d_bonus.h"

int	game_management(int keycode, t_all *game_struct)
{
	if (keycode == 'e')
		door_management(game_struct);
	else if (keycode == XK_Escape)
		exit(1);//faire un fonction destroy avec free et destroy_images
	else
		movement_management(keycode, game_struct);
	return (0);
}
