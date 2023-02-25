#include "cub3d.h"

int	game_management(int keycode, t_all *game_struct)
{
	if (keycode == XK_Escape)
		destroy(game_struct);
	else
		movement_management(keycode, game_struct);
	return (0);
}
