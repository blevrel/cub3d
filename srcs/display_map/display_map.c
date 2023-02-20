#include "cub3d.h"

void	put_vertical_line(float distance, int pxl_horizontal, t_img_data render_img)
{
	int	wall_height;
	int	pxl_vertical;
	int	pxl_sky_and_floor;

	wall_height = WIN_HEIGHT / distance;
	pxl_sky_and_floor = (WIN_HEIGHT - wall_height) / 2;
	pxl_vertical = 0;
	while (pxl_vertical < WIN_HEIGHT)
	{
		if (pxl_vertical <= pxl_sky_and_floor)
			my_pixel_put(&render_img, pxl_horizontal, pxl_vertical, 0xFFC5BF);
		else if (pxl_vertical >= pxl_sky_and_floor + wall_height)
			my_pixel_put(&render_img, pxl_horizontal, pxl_vertical, 0xC6DBDA);
		else
			my_pixel_put(&render_img, pxl_horizontal, pxl_vertical, 0xECD5E3);
		pxl_vertical++;
	}
}
