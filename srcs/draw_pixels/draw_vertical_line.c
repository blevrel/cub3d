#include "cub3d.h"

t_img_data	draw_vertical_line(t_img_data render_img, t_render_data render_data,
				float x/*, surement la hauteur du mur a passer en parametre*/)
{
	int	y;

	while (x < WIN_WIDTH)
	{
		y = 0;
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
		x++;
	}
	return (render_img);
}
