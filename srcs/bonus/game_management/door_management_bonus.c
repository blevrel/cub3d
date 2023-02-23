#include "cub3d_bonus.h"

static char	**update_mat(char **mat, int x, int y, t_player player)
{
	int	x_mat;
	int	y_mat;

	x_mat = player.pxl_x / SQ_SIZE;
	y_mat = player.pxl_y / SQ_SIZE;
	if (x)
	{
		if (mat[y_mat][x] == '2')
			mat[y_mat][x] = '3';
		else if (mat[y_mat][x] == '3')
			mat[y_mat][x] = '2';
	}
	if (y)
	{
		if (mat[y][x_mat] == '2')
			mat[y][x_mat] = '3';
		else if (mat[y][x_mat] == '3')
			mat[y][x_mat] = '2';
	}
	return (mat);
}

static char	**manage_door(char **mat, t_player player)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (player.angle > M_PI / 4 && player.angle < 3 * M_PI / 4)
		y = player.pxl_y / SQ_SIZE - 1;
	else if (player.angle > 3 * M_PI / 4 && player.angle < 5 * M_PI / 4)
		x = player.pxl_x / SQ_SIZE - 1;
	else if (player.angle > 5 * M_PI / 4 && player.angle < 7 * M_PI / 4)
		y = player.pxl_y / SQ_SIZE + 1;
	else if (player.angle > 7 * M_PI / 4 || player.angle <  M_PI / 4)
		x = player.pxl_x / SQ_SIZE + 1;
	if (x || y)
		mat = update_mat(mat, x, y, player);
	return (mat);
}

int	door_management(t_all *game_struct)
{
	game_struct->mat = manage_door(game_struct->mat, game_struct->player);
	cast_rays(game_struct);
	display_minimap(*game_struct);
	return (0);
}
