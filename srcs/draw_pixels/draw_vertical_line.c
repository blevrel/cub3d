#include "cub3d.h"

t_img_data	draw_vertical_line(t_img_data render_img, t_render_data render_data,
				int x, float distance)
{
	int	y;

	y = 0;
	(void)distance;
	while (y < WIN_HEIGHT)
	{
		if (y < 200 /* haut du mur*/)
			my_pixel_put(&render_img, x, y, render_data.c_color);
		else if (y > 800 /* bas du mur*/)
			my_pixel_put(&render_img, x, y, render_data.f_color);
		else
			my_pixel_put(&render_img, x, y, WALL_COLOR);
		y++;
	}
	return (render_img);
}
