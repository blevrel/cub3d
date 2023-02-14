#include "cub3d.h"

void	cast_ray(t_player player, /*char **mat,*/ int i)
{
	float	next_intersection_x;
	float	next_intersection_y;
	float	distance_next_x;
	float	distance_next_y;

	(void)i;
	next_intersection_x = floor(player.pxl_x / SQ_SIZE) +
		(cos(player.angle) > 0);
	next_intersection_y = floor(player.pxl_y / SQ_SIZE) +
		(sin(player.angle) > 0);
	distance_next_x = (next_intersection_x - player.pxl_x) / cos(player.angle);
	distance_next_y = (next_intersection_y - player.pxl_y) / sin(player.angle);
}

void	raycasting_render(t_all *game_struct)
{
	t_img_data	render_img;
//	float		ray_lenght;
//	int			i;

//	i = 0;
	render_img.img = mlx_new_image(game_struct->window.mlx, WIN_WIDTH, WIN_HEIGHT);
	render_img.addr = mlx_get_data_addr(render_img.img, &render_img.bits_per_pixel,
			&render_img.line_length, &render_img.endian);
	/*while (i < FOV)
	{
		//calculer la hauteur du mur dans cast_ray ou autre part peut etre jsp
		ray_lenght = cast_ray(game_struct->pos, game_struct->mat, i);
		printf("%f\n", ray_lenght);
	//	draw_vertical_line(render_img, game_struct->render_data, 0);
		i++;
	}*/
//	mlx_put_image_to_window(game_struct->window.mlx,
//		game_struct->window.win_ptr, render_img.img, 0, 0);
}
