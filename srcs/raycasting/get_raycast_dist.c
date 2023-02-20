#include "cub3d.h"

static t_raycast_dist	get_first_delta_dist(float raydir_x, float raydir_y)
{
	t_raycast_dist	distance;

	distance.delta_x = fabs(1 / raydir_x);
	if (!raydir_x)
		distance.delta_x = pow(10, 30);
	distance.delta_y = fabs(1 / raydir_y);
	if (!raydir_y)
		distance.delta_y = pow(10, 30);
	return (distance);
}

static t_raycast_dist	get_first_side_dist(float pxl_x, float pxl_y,
	t_raycast_dist distance, t_raycast_dir direction)
{
	if (direction.raydir_x < 0)
	{
		distance.side_x = (pxl_x - floor(pxl_x)) * distance.delta_x;
		distance.step_x = -1;
	}
	else
	{
		distance.side_x = (floor(pxl_x) + 1 - pxl_x) * distance.delta_x;
		distance.step_x = 1;
	}
	if (direction.raydir_y < 0)
	{
		distance.side_y = (pxl_y - floor(pxl_y)) * distance.delta_y;
		distance.step_y = -1;
	}
	else
	{
		distance.side_y = (floor(pxl_y) + 1 - pxl_y) * distance.delta_y;
		distance.step_y = 1;
	}
	return (distance);
}

t_raycast_dist	get_raycast_dist(t_raycast_dir direction, t_player player)
{
	t_raycast_dist	distance;

	distance = get_first_delta_dist(direction.raydir_x, direction.raydir_y);
	distance = get_first_side_dist(player.pxl_x, player.pxl_y, distance, direction);
	return (distance);
}
