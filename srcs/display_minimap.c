#include "cub3d.h"

int	pick_pixel_color(char **mat, int x_pxl, int y_pxl, t_map_data map_data)
{
	int	x_pos_in_mat;
	int	y_pos_in_mat;

	x_pos_in_mat = x_pxl / SQ_SIZE;
	y_pos_in_mat = y_pxl / SQ_SIZE;
	if ((x_pos_in_mat <= 0 || x_pos_in_mat >= map_data.map_width - 1)
			|| (y_pos_in_mat <= 0 || y_pos_in_mat >= map_data.map_height - 1)
			|| mat[y_pos_in_mat][x_pos_in_mat] == '1'
			|| mat[y_pos_in_mat][x_pos_in_mat] == ' ')
		return (WALL_COLOR);
	else if (mat[y_pos_in_mat][x_pos_in_mat] == '0')
		return (FLOOR_COLOR);
	else
		return (PLAYER_COLOR);
}

t_img_data	put_minimap_pixel(t_img_data img, int color)
{
	static int	img_x = 1;
	static int	img_y = 1;

	if (color == PLAYER_COLOR)
	{
		if ((img_x > (MINI_WIDTH - 15) / 2 && img_x < (MINI_WIDTH + 15) / 2)
			&& (img_y > (MINI_HEIGHT - 15) / 2
			&& img_y < (MINI_HEIGHT + 15) / 2))
			my_pixel_put(&img, img_x, img_y, color);
		else
			my_pixel_put(&img, img_x, img_y, FLOOR_COLOR);
		img_x++;
		return (img);
	}
	my_pixel_put(&img, img_x, img_y, color);
	img_x++;
	if (img_x == MINI_WIDTH)
	{
		img_y++;
		img_x = 1;
	}
	if (img_y == MINI_HEIGHT)
		img_y = 1;
	return (img);
}

t_img_data	check_around_player(t_img_data img, /*t_player player,*/
	char **mat, t_map_data map_data)
{
	int	x_pxl = 19 * SQ_SIZE + 16;
	int	y_pxl = 6 * SQ_SIZE + 16;
	int	y_check = y_pxl - (MINI_VISION * SQ_SIZE);
	int	x_check;
	int	x_pxl_limit = x_pxl + (MINI_VISION * SQ_SIZE);
	int	y_pxl_limit = y_pxl + (MINI_VISION * SQ_SIZE);
	int	color;

	while (y_check < y_pxl_limit)
	{
		x_check = x_pxl - (MINI_VISION * SQ_SIZE);
		while (x_check < x_pxl_limit)
		{
			color = pick_pixel_color(mat, x_check, y_check, map_data);
			img = put_minimap_pixel(img, color);
			x_check++;
		}
		y_check++;
	}
	return (img);
}

void	display_minimap(char **mat, /*t_player player,*/ t_window window,
			t_map_data map_data)
{
	t_img_data	minimap;

	minimap.img = mlx_new_image(window.mlx, MINI_WIDTH + 1, MINI_HEIGHT + 1);
	minimap.addr = mlx_get_data_addr(minimap.img, &minimap.bits_per_pixel,
			&minimap.line_length, &minimap.endian);
	minimap = draw_border(minimap);
	minimap = check_around_player(minimap, mat, map_data);
	mlx_put_image_to_window(window.mlx, window.win_ptr, minimap.img, MINI_POS, MINI_POS);
	//(void)player;
}
