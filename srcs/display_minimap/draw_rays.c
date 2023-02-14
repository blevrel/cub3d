#include "cub3d.h"

t_img_data	draw_rays(t_img_data minimap, t_player player, char **mat)
{
	float	next_intersection_x;
	float	next_intersection_y;
	float	distance_next_x;
	float	distance_next_y;

	//(void)i;
	(void)mat;
	next_intersection_x = floor(player.pxl_x) +
		(cos(player.angle) > 0);
	next_intersection_y = floor(player.pxl_y) +
		(sin(player.angle) > 0);
	distance_next_x = (next_intersection_x - player.pxl_x) / cos(player.angle);
	distance_next_y = (next_intersection_y - player.pxl_y) / sin(player.angle);
	//my_pixel_put(&minimap, next_intersection_x * SQ_SIZE,
	//	next_intersection_y * SQ_SIZE, PLAYER_COLOR);
	printf("x : %f\n", next_intersection_x);
	printf("y : %f\n", next_intersection_y);
	return (minimap);
}
