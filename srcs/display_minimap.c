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
	else
		return (FLOOR_COLOR);
}

t_img_data	put_minimap_pixel(t_img_data img, int color)
{
	static int	img_x = 1;
	static int	img_y = 1;

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


t_img_data	draw_player(t_img_data img, t_triangle triangle)
{
    int x;
    int y;
    int max_x;
    int max_y;

    max_x = ft_max(triangle.x_a, ft_max(triangle.x_b, triangle.x_c));
    max_y = ft_max(triangle.y_a, ft_max(triangle.y_b, triangle.y_c));
    x = ft_min(triangle.x_a, ft_min(triangle.x_b, triangle.x_c));
    while (x <= max_x)
	{
    	y = ft_min(triangle.y_a, ft_min(triangle.y_b, triangle.y_c));
        while (y <= max_y)
		{
            if ((triangle.y_b - triangle.y_c) * x + (triangle.x_c - triangle.x_b) * y + triangle.x_b * triangle.y_c - triangle.x_c * triangle.y_b >= 0
				&& (triangle.y_c - triangle.y_a) * x + (triangle.x_a - triangle.x_c) * y + triangle.x_c * triangle.y_a - triangle.x_a * triangle.y_c >= 0
				&& (triangle.y_a - triangle.y_b) * x + (triangle.x_b - triangle.x_a) * y + triangle.x_a * triangle.y_b - triangle.x_b * triangle.y_a >= 0)
				my_pixel_put(&img, x, y, PLAYER_COLOR);
			y++;
		}
		x++;
	}
	return (img);
}

t_img_data	fill_minimap(t_img_data img, /*t_player player,*/
	char **mat, t_map_data map_data)
{
	int	x_pxl = 19 * SQ_SIZE + 16;
	int	y_pxl = 6 * SQ_SIZE + 16;
	int	y_check = y_pxl - (MINI_VISION * SQ_SIZE);
	int	x_check;
	int	x_pxl_limit = x_pxl + (MINI_VISION * SQ_SIZE);
	int	y_pxl_limit = y_pxl + (MINI_VISION * SQ_SIZE);
//	float	angle = 0;
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
	t_triangle	player_triangle;

	player_triangle = get_triangle_coords(90);
	minimap.img = mlx_new_image(window.mlx, MINI_WIDTH + 1, MINI_HEIGHT + 1);
	minimap.addr = mlx_get_data_addr(minimap.img, &minimap.bits_per_pixel,
			&minimap.line_length, &minimap.endian);
	minimap = draw_border(minimap);
	minimap = fill_minimap(minimap, mat, map_data);
	minimap = draw_player(minimap, player_triangle);
	mlx_put_image_to_window(window.mlx, window.win_ptr, minimap.img, MINI_POS, MINI_POS);
	//(void)player;
}
