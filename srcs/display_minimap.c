#include "cub3d.h"

t_img_data	draw_border(t_img_data img)
{
	int	i;

	i = 0;
	while (i <= MINI_WIDTH)
	{
		my_pixel_put(&img, i, 0, BORDER_COLOR);
		my_pixel_put(&img, i, MINI_HEIGHT, BORDER_COLOR);
		i++;
	}
	i = 0;
	while (i <= MINI_HEIGHT)
	{
		my_pixel_put(&img, 0, i, BORDER_COLOR);
		my_pixel_put(&img, MINI_WIDTH, i, BORDER_COLOR);
		i++;
	}
	return (img);
}

t_img_data	draw_square_at_coordinates(t_img_data img, int x, int y, int color)
{
	int	save_x;
	int	save_y;

	save_y = y;
	save_x = x;
	while (y < MINI_SQ_SIZE + save_y)
	{
		x = save_x;
		while (x < MINI_SQ_SIZE + save_x)
		{
			my_pixel_put(&img, x, y, color);
			x++;
		}
		y++;
	}
	return (img);
}

t_img_data	fill_minimap_square(t_img_data img, int element)
{
	static int	x = 1;
	static int	y = 1;

	if (element == FLOOR)
		draw_square_at_coordinates(img, x, y, FLOOR_COLOR);
	if (element == WALL)
		draw_square_at_coordinates(img, x, y, WALL_COLOR);
	if (element == PLAYER)
	{
		draw_square_at_coordinates(img, x, y, FLOOR_COLOR);
		//case particuliere, rajouter le joueur par dessus les couleurs du sol
	}
	x += 64;
	if (x == 193)
	{
		y += 64;
		x = 1;
	}
	if (y == 193)
		y = 1;
	return (img);
}

t_img_data	check_around_player(t_img_data img, /*t_player player, */char **mat)
{
	int	x_check;
	int	y_check;

	//y = player.pos_y - 1;
	y_check = 1;
	while (y_check < 4)
	{
		//x = player.pos_x - 1;
		x_check = 3;
		while (x_check < 6)
		{
			if (mat[y_check][x_check] == '0')
				img = fill_minimap_square(img, FLOOR);
			else if (mat[y_check][x_check] == 2 || mat[y_check][x_check] == '1')
				img = fill_minimap_square(img, WALL);
			else
				img = fill_minimap_square(img, PLAYER);
			x_check++;
		}
		y_check++;
	}
	return (img);
}

void	display_minimap(char **mat, /*t_player player,*/ t_window window)
{
	t_img_data	minimap;

	minimap.img = mlx_new_image(window.mlx, MINI_WIDTH + 1, MINI_HEIGHT + 1);
	minimap.addr = mlx_get_data_addr(minimap.img, &minimap.bits_per_pixel,
			&minimap.line_length, &minimap.endian);
	minimap = draw_border(minimap);
	minimap = check_around_player(minimap, mat);
	mlx_put_image_to_window(window.mlx, window.win_ptr, minimap.img, MINI_POS, MINI_POS);
	//(void)player;
}
