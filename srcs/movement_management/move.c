#include "cub3d.h"

static t_player	go_up(t_player pos)
{
	pos.pxl_x += (cos(pos.angle) * MOVESPEED);
	pos.pxl_y -= (sin(pos.angle) * MOVESPEED);
	return (pos);
}

static t_player	go_down(t_player pos)
{
	pos.pxl_x -= (cos(pos.angle) * MOVESPEED);
	pos.pxl_y += (sin(pos.angle) * MOVESPEED);
	return (pos);
}

static t_player	go_left(t_player pos)
{
	pos.pxl_x -= (sin(pos.angle) * MOVESPEED);
	pos.pxl_y -= (cos(pos.angle) * MOVESPEED);
	return (pos);
}

static t_player	go_right(t_player pos)
{
	pos.pxl_x += (sin(pos.angle) * MOVESPEED);
	pos.pxl_y += (cos(pos.angle) * MOVESPEED);
	return (pos);
}

t_player	move(int keycode, t_player pos)
{
	if (keycode == 'w')
		pos = go_up(pos);
	else if (keycode == 's')
		pos = go_down(pos);
	else if (keycode == 'a')
		pos = go_left(pos);
	else if (keycode == 'd')
		pos = go_right(pos);
	return (pos);
}
