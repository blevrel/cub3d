#include "cub3d.h"

void	get_side_of_wall_hit(t_render_data *render_data,
				t_raycast_dist distance, t_raycast_dir direction)
{
	float	angle;

	angle = atan2(direction.raydir_y, direction.raydir_x);
	if (distance.side == 1 && angle < 0)
		render_data->wall_side = NORTH;
	else if (distance.side == 1 && angle > 0)
		render_data->wall_side = SOUTH;
	else if (distance.side == 0 && (angle > M_PI / 2 || angle < -M_PI / 2))
		render_data->wall_side = WEST;
	else
		render_data->wall_side = EAST;
}

float	get_ray_hit_coords(t_raycast_dist distance, t_player player,
			float perp_wall_dist, t_raycast_dir direction)
{
	float			x;

	if (distance.side == 0)
		x = player.pxl_y + perp_wall_dist * direction.raydir_y;
	if (distance.side == 1)
		x = player.pxl_x + perp_wall_dist * direction.raydir_x;
	printf("%f\n", x);
	x -= floor(x);
	return (x);
}
