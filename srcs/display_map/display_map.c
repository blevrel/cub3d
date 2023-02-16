#include "cub3d.h"

static int	get_wall_height(float horizontal_distance, float vertical_distance)
{
	int	wall_height;

	wall_height = 32 * horizontal_distance / 138;
	if (vertical_distance < horizontal_distance)
		wall_height = 32 * vertical_distance / 138;
	return (wall_height);
}

static void	displaying(t_img_data *map, int wall_height,
	int pxl_horizontal)
{
	int	pxl_vertical;
	int	pxl_sky_and_floor;

	pxl_vertical = 1;
	pxl_sky_and_floor = (1080 - wall_height) / 2;
	while (pxl_vertical < 1080)
	{
		if (pxl_vertical <= pxl_sky_and_floor)
			my_pixel_put(map, pxl_horizontal, pxl_vertical, 0x0000FF);
		else if (pxl_vertical >= pxl_sky_and_floor + wall_height)
			my_pixel_put(map, pxl_horizontal, pxl_vertical, 0x00FF00);
		else
			my_pixel_put(map, pxl_horizontal, pxl_vertical, 0xFF0000);
		pxl_vertical++;
	}
}

void	test_displaying(t_img_data *map, int wall_height)
{
	int	pxl_x;

	pxl_x = 1;
	while (pxl_x < 1920)
	{
		displaying(map, wall_height, pxl_x);
		pxl_x++;
	}
}

void	display_map(float horizontal_distance, float vertical_distance, 
	/*int pxl_horizontal, */t_window window)
{
	t_img_data	map;
	int			wall_height;
	
	map.img = mlx_new_image(window.mlx, WIN_WIDTH, WIN_HEIGHT);
	map.addr = mlx_get_data_addr(map.img, &map.bits_per_pixel,
		&map.line_length, &map.endian);
	wall_height = get_wall_height(horizontal_distance, vertical_distance);
	test_displaying(&map, wall_height);//a supprimer
	//displaying(&map, wall_height, pxl_horizontal);
	mlx_put_image_to_window(window.mlx, window.win_ptr, map.img,
		MINI_POS, MINI_POS);
}
