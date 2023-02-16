#include "cub3d.h"

void	display_map(float distance, int pxl_horizontal, t_img_data render_img)
{
	int	wall_height;
	int	pxl_vertical;
	int	pxl_sky_and_floor;

	wall_height = SQ_SIZE * WALL_SIZE / distance;
	pxl_sky_and_floor = (WIN_HEIGHT - wall_height) / 2;
	pxl_vertical = 0;
	while (pxl_vertical < WIN_HEIGHT)
	{
		if (pxl_vertical <= pxl_sky_and_floor)
			my_pixel_put(&render_img, pxl_horizontal, pxl_vertical, 0x0000FF);
		else if (pxl_vertical >= pxl_sky_and_floor + wall_height)
			my_pixel_put(&render_img, pxl_horizontal, pxl_vertical, 0x00FF00);
		else
			my_pixel_put(&render_img, pxl_horizontal, pxl_vertical, 0xFF0000);
		pxl_vertical++;
	}
}
