#include "cub3d.h"

static t_raycast_dir	get_camera_and_raydir(t_raycast_dir direction,
			int ray_index)
{
	direction.camera_x = 2 * ray_index / (float)WIN_WIDTH - 1;
	direction.raydir_x = direction.dir_x + direction.plane_x * direction.camera_x;
	direction.raydir_y = direction.dir_y + direction.plane_y * direction.camera_x;
	return (direction);
}

static t_raycast_dist	get_side_dist(t_raycast_dist distance, t_player player, char **mat)
{
	int	hit;
	int	map_x;
	int	map_y;

	hit = 0;
	map_x = player.pxl_x  / SQ_SIZE;
	map_y = player.pxl_y  / SQ_SIZE;
	while (hit != '1')
	{
		if (distance.side_x < distance.side_y)
		{
			distance.side_x += distance.delta_x;
			map_x += distance.step_x;
			distance.side = 0;
		}
		else
		{
			distance.side_y += distance.delta_y;
			map_y += distance.step_y;
			distance.side = 1;
		}
		hit = mat[map_y][map_x];
	}
	return (distance);
}

static float	get_dist_from_wall(t_raycast_dist distance)
{
	float	perp_wall_dist;

	perp_wall_dist = distance.side_x - distance.delta_x;
	if (distance.side)
		perp_wall_dist = distance.side_y - distance.delta_y;
	return (perp_wall_dist);
}

void	cast_rays(t_all *game_struct)
{
	float			perp_wall_dist;
	int				ray_index;

	ray_index = 0;
	while (ray_index < WIN_WIDTH)
	{
		game_struct->direction = get_camera_and_raydir(game_struct->direction,
			ray_index);
		game_struct->distance = get_raycast_dist(game_struct->direction,
			game_struct->player);
		game_struct->distance = get_side_dist(game_struct->distance,
			game_struct->player, game_struct->mat);
		perp_wall_dist = get_dist_from_wall(game_struct->distance);
		put_vertical_line(perp_wall_dist, ray_index,
			game_struct->render_images.window_render);
		ray_index++;
	}
	mlx_put_image_to_window(game_struct->window.mlx,
		game_struct->window.win_ptr, game_struct->render_images.window_render.img,
		0, 0);
}
