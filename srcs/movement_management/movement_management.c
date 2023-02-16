#include "cub3d.h"

static float	go_left_or_right(int keycode, float angle)
{
	if (keycode == XK_Left)
	{
		angle += (5 * M_PI / 180);
		if (angle > 2 * M_PI)
			angle -= 2 * M_PI;
	}
	else if (keycode == XK_Right)
	{
		angle -= (5 * M_PI / 180);
		if (angle < 0)
			angle += 2 * M_PI;
	}
	return (angle);
}

int	movement_management(int keycode, t_all *game_struct)
{
	if (keycode == XK_Escape)
		exit(1);//faire un fonction destroy avec free et destroy_images
	else if (keycode == XK_Left || keycode == XK_Right)
	{
		game_struct->player.angle = go_left_or_right(keycode, \
			game_struct->player.angle);
		cast_rays(*game_struct);
		display_minimap(*game_struct);
	}
	else if (keycode == 'w' || keycode == 's'
		|| keycode == 'a' || keycode == 'd')
	{
		game_struct->player = move(keycode, game_struct->player, game_struct->mat);
		cast_rays(*game_struct);
		display_minimap(*game_struct);
	}
	return (0);
}
