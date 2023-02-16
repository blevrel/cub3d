#include "cub3d.h"

bool	ray_is_in_map(float x, float y, t_map_data map_data)
{
	if (x > map_data.map_width)
		return (false);
	if (y > map_data.map_height)
		return (false);
	if (x < 0)
		return (false);
	if (y < 0)
		return (false);
	return (true);
}

t_wall_coords	get_horizontal_wall(t_player player, char **mat, float player_angle, t_map_data map_data)
{
	t_wall_coords	wall;
	int				incr_x;
	int				incr_y;
	char			hit;

	hit = 0;
	if (player_angle == 0 || fabs(player_angle - M_PI) < 0.0001 || fabs(player_angle - (M_PI * 2)) < 0.0001) //sides
	{
		wall.x = -1;
		wall.y = -1;
		return (wall);
	}
	else if (player_angle < M_PI) //ray facing up
	{
		wall.y = floor(player.pxl_y / SQ_SIZE) * SQ_SIZE - 1;
		wall.x = player.pxl_x + (player.pxl_y - wall.y) / tan(player_angle);
		incr_y = -SQ_SIZE;
		incr_x = SQ_SIZE / tan(player_angle);
	}
	else if (player_angle > M_PI) //ray facing down
	{
		wall.y = floor(player.pxl_y / SQ_SIZE) * SQ_SIZE + SQ_SIZE;
		wall.x = player.pxl_x + (player.pxl_y - wall.y) / tan(player_angle);
		incr_y = SQ_SIZE;
		incr_x = SQ_SIZE / tan(player_angle);
	}
	while (hit != '1' && ray_is_in_map(floor(wall.x / SQ_SIZE), floor(wall.y / SQ_SIZE), map_data))
	{
		if (ray_is_in_map(floor(wall.x / SQ_SIZE), floor(wall.y / SQ_SIZE), map_data))
			hit = mat[(int)floor(wall.y / SQ_SIZE)][(int)floor(wall.x / SQ_SIZE)];
		else
		{
			wall.x -= incr_x;
			wall.y -= incr_y;
			hit = '1';
			continue ;
		}
		wall.x += incr_x;
		wall.y += incr_y;
	}
	return (wall);
}

t_wall_coords	get_vertical_wall(t_player player, char **mat, float player_angle, t_map_data map_data)
{
	t_wall_coords	wall;
	int				incr_x;
	int				incr_y;
	char			hit;

	hit = 0;
	if (fabs(player_angle - (M_PI / 2)) < 0.0001 || fabs(player_angle  - (3 * M_PI /2)) < 0.0001) //up down
	{
		wall.x = -1;
		wall.y = -1;
		return (wall);
	}
	else if ((player_angle > M_PI / 2) && (player_angle < 3 * M_PI / 2)) //ray facing left
	{
		wall.x = floor(player.pxl_x / SQ_SIZE) * SQ_SIZE - 1;
		wall.y = player.pxl_y + (player.pxl_x - wall.x) * tan(player_angle);
		incr_x = -SQ_SIZE;
		incr_y = floor(SQ_SIZE * tan(player_angle));
	}
	else if ((player_angle <= M_PI / 2) || (player_angle >= 3 * M_PI / 2)) //ray facing right
	{
		wall.x = floor(player.pxl_x / SQ_SIZE) * SQ_SIZE + SQ_SIZE;
		wall.y = floor(player.pxl_y + (player.pxl_x - wall.x) * tan(player_angle));
		incr_x = SQ_SIZE;
		incr_y = floor(SQ_SIZE * tan(player_angle));
	}
	while (hit != '1' && ray_is_in_map(floor(wall.x / SQ_SIZE), floor(wall.y / SQ_SIZE), map_data))
	{
		if (ray_is_in_map(floor(wall.x / SQ_SIZE), floor(wall.y / SQ_SIZE), map_data))
			hit = mat[(int)floor(wall.y / SQ_SIZE)][(int)floor(wall.x / SQ_SIZE)];
		else
		{
			wall.x -= incr_x;
			wall.y -= incr_y;
			hit = '1';
			continue ;
		}
		wall.x += incr_x;
		wall.y += incr_y;
	}
	return (wall);
}

float	get_distance(t_player player, t_wall_coords horiz_wall)
{
	float	x_squared;
	float	y_squared;
	float	dist;

	x_squared = (player.pxl_x - horiz_wall.x) * (player.pxl_x - horiz_wall.x);
	y_squared = (player.pxl_y - horiz_wall.y) * (player.pxl_y - horiz_wall.y);
	dist = sqrt(x_squared + y_squared);
	return (dist);
}

void	cast_rays(t_all game_struct)
{
	int				i;
	t_wall_coords	wall;
	float			distance_horiz;
	float			distance_vertic;
	float			distance;
	float			player_angle_cpy;

	i = 0;
	player_angle_cpy = game_struct.player.angle + ((float)FOV / 2);
	while (player_angle_cpy > game_struct.player.angle - ((float)FOV / 2))
	{
		printf("%f\n", player_angle_cpy);
		wall = get_horizontal_wall(game_struct.player, game_struct.mat, player_angle_cpy, game_struct.map_data);
		distance_horiz = get_distance(game_struct.player, wall);
		wall = get_vertical_wall(game_struct.player, game_struct.mat, player_angle_cpy, game_struct.map_data);
		distance_vertic = get_distance(game_struct.player, wall);
		if (distance_horiz > distance_vertic)
			distance = distance_vertic;
		else
			distance = distance_horiz;
		display_map(distance, i, game_struct.render_images.window_render);
		player_angle_cpy -= ((float)FOV / WIN_WIDTH);
		i++;
	}
	mlx_put_image_to_window(game_struct.window.mlx, game_struct.window.win_ptr, game_struct.render_images.window_render.img, 0, 0);
}
