#include "../../includes/cub3d.h"

static float	go_left_or_right(int keycode, float angle)
{
	if (keycode == XK_Left)
	{
		angle -= (5 * PI / 180);
		if (angle < 0)
			angle += 2;
	}
	else if (keycode == XK_Right)
	{
		angle += (5 * PI / 180);
		if (angle > 2)
			angle -= 2;
	}
	return (angle);
}

int	movement_management(int keycode, t_all *game_struct)
{
	if (keycode == XK_Left || keycode == XK_Right)
		game_struct->pos.angle = go_left_or_right(keycode, \
			game_struct->pos.angle);
	else
		game_struct->pos = move(keycode, game_struct);
	return (0);
}
