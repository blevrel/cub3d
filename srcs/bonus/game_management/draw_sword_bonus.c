
#include "cub3d_bonus.h"

//time % nb de frames
//pour choisir le sprite a afficher
static void	*select_sprite(t_render_data render_data)
{
	return (render_data.s_three_image);
}

static int	get_sprite_color(t_render_data render_data, int y, int x)
{
	t_img_data	image;
	int			i;
	int			color;

	color = 0;
	image.img = select_sprite(render_data);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	i = ((x * SPRITE_WIDTH) + y) * 4;
	color = color | (unsigned char)(image.addr[i + 2]);
	color = color << 8;
	color = color | (unsigned char)(image.addr[i + 1]);
	color = color << 8;
	color = color | (unsigned char)(image.addr[i]);
	return (color);
}

void	draw_sword(t_render_data render_data, t_window window,
			t_render_images render_images)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	color;

	j = 0;
	y = (WIN_HEIGHT / 2) - (SPRITE_HEIGHT / 2);
	while (j < SPRITE_HEIGHT)
	{
		i = 0;
		x = (WIN_WIDTH / 2) - (SPRITE_WIDTH / 2);
		while (i < SPRITE_WIDTH)
		{
			color = get_sprite_color(render_data, j, i);
			my_pixel_put(&render_images.window_render, x, y, color);
			i++;
			x++;
		}
		j++;
		y++;
	}
	mlx_put_image_to_window(window.mlx,
		window.win_ptr, render_images.window_render.img,
		0, 0);
}
