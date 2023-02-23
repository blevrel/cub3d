#include "cub3d_bonus.h"

t_raycast_dir	get_new_dir_and_plane(t_raycast_dir direction,
	float angle)
{
	direction.dir_x = cos(angle);
	direction.dir_y = -sin(angle);
	direction.plane_x = PLANE * sin(angle);
	direction.plane_y = PLANE * cos(angle);
	return (direction);
}
