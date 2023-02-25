#include "cub3d_bonus.h"

static void	*select_sprite(t_render_data render_data)
{
	//renvoyer la texture correspondant a la frame que nous devons afficher
	//selon ce que jordan a fait
	return (render_data.s_six_image);
}

static int	get_texture_color(t_render_data render_data, int y, int x)
{
	t_img_data	image;
	int			i;
	int			color;

	color = 0;
	image.img = select_sprite(render_data);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	i = ((x * render_data.width) + y) * 4;
	color = color | (unsigned char)(image.addr[i + 2]);
	color = color << 8;
	color = color | (unsigned char)(image.addr[i + 1]);
	color = color << 8;
	color = color | (unsigned char)(image.addr[i]);
	return (color);
}

void	put_animation_on_texture(float distance, int pxl_horizontal,
t_img_data render_img, t_render_data render_data)
{
	int		wall_height;
	int		pxl_vertical;
	int		pxl_sky_and_floor;
	int		color;
	double	ratio;

	wall_height = WIN_HEIGHT / distance;
	ratio = (double)render_data.width / (double)wall_height;
	pxl_sky_and_floor = (WIN_HEIGHT - wall_height) / 2;
	pxl_vertical = 0;
	while (pxl_vertical < WIN_HEIGHT)
	{
		if (pxl_vertical > pxl_sky_and_floor && pxl_vertical
			< pxl_sky_and_floor + wall_height)
		{
			color = get_texture_color(render_data,
				(pxl_vertical - pxl_sky_and_floor) * ratio, render_data.tex_x);
			if (color != 0x000000)
				my_pixel_put(&render_img, pxl_horizontal, pxl_vertical, color);
		}
		pxl_vertical++;
	}
}
