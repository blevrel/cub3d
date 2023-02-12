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
	printf("angle = %f\n", angle);
	return (angle);
}

int	movement_management(int keycode, t_all *game_struct)
{
	if (keycode == XK_Left || keycode == XK_Right)
	{
		game_struct->pos.angle = go_left_or_right(keycode, 
			game_struct->pos.angle);
		display_minimap(game_struct->mat, game_struct->pos, game_struct->window,
			game_struct->map_data);
	}
	else if (keycode == 'w' || keycode == 's'
		|| keycode == 'a' || keycode == 'd')
	{
		game_struct->pos = move(keycode, game_struct->pos);
		display_minimap(game_struct->mat, game_struct->pos, game_struct->window,
			game_struct->map_data);
	}
	return (0);
}