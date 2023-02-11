#include "cub3d.h"

static t_player	go_up(t_all *game_struct)
{
	game_struct->pos.pxl_x += (cos(game_struct->pos.angle) * MOVESPEED);
	game_struct->pos.pxl_y -= (sin(game_struct->pos.angle) * MOVESPEED);
	return (game_struct->pos);
}

static t_player	go_down(t_all *game_struct)
{
	game_struct->pos.pxl_x -= (cos(game_struct->pos.angle) * MOVESPEED);
	game_struct->pos.pxl_y += (sin(game_struct->pos.angle) * MOVESPEED);
	return (game_struct->pos);
}

static t_player	go_left(t_all *game_struct)
{
	game_struct->pos.pxl_x -= (sin(game_struct->pos.angle) * MOVESPEED);
	game_struct->pos.pxl_y -= (cos(game_struct->pos.angle) * MOVESPEED);
	return (game_struct->pos);
}

static t_player	go_right(t_all *game_struct)
{
	game_struct->pos.pxl_x += (sin(game_struct->pos.angle) * MOVESPEED);
	game_struct->pos.pxl_y += (cos(game_struct->pos.angle) * MOVESPEED);
	return (game_struct->pos);
}

t_player	move(int keycode, t_all *game_struct)
{
	if (keycode == 'w')
		game_struct->pos = go_up(game_struct);
	else if (keycode == 's')
		game_struct->pos = go_down(game_struct);
	else if (keycode == 'a')
		game_struct->pos = go_left(game_struct);
	else if (keycode == 'd')
		game_struct->pos = go_right(game_struct);
	ft_printf("pxl_x = %d\npxl_y = %d\n", \
		game_struct->pos.pxl_x, game_struct->pos.pxl_y);
	return (game_struct->pos);
}
