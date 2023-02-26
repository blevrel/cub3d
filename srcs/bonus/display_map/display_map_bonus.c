#include "cub3d_bonus.h"

static void	*select_texture(t_render_data render_data)
{
	if (render_data.door_wall == 1)
		return (render_data.door_image);
	if (render_data.wall_side == NORTH)
		return (render_data.no_image);
	if (render_data.wall_side == SOUTH)
		return (render_data.so_image);
	if (render_data.wall_side == WEST)
		return (render_data.we_image);
	if (render_data.wall_side == EAST)
		return (render_data.ea_image);
	return (NULL);
}

static int	get_texture_color(t_render_data render_data, int y, int x)
{
	t_img_data	image;
	int			i;
	int			color;

	color = 0;
	image.img = select_texture(render_data);
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

int	get_texture_coords(t_render_data render_data, t_raycast_dist distance,
		t_raycast_dir direction)
{
	int	tex_x;

	tex_x = render_data.ray_hit_x * (float)render_data.width;
	if (distance.side == 0 && direction.raydir_x > 0)
		tex_x = render_data.width - tex_x - 1;
	if (distance.side == 1 && direction.raydir_y < 0)
		tex_x = render_data.width - tex_x - 1;
	return (tex_x);
}

void	put_vertical_line(float distance, int pxl_horizontal,
	t_img_data render_img, t_render_data render_data)
{
	int		wall_height;
	int		pxl_vertical;
	int		color;
	double	ratio;

	wall_height = WIN_HEIGHT / distance;
	ratio = (double)render_data.width / (double)wall_height;
	pxl_vertical = 0;
	while (pxl_vertical < WIN_HEIGHT)
	{
		if (pxl_vertical <= (WIN_HEIGHT - wall_height) / 2)
			my_pixel_put(&render_img, pxl_horizontal, pxl_vertical,
				render_data.c_color);
		else if (pxl_vertical >= WIN_HEIGHT / 2 + wall_height / 2)
			my_pixel_put(&render_img, pxl_horizontal, pxl_vertical,
				render_data.f_color);
		else
		{
			color = get_texture_color(render_data,
					(pxl_vertical - (WIN_HEIGHT - wall_height) / 2)
					* ratio, render_data.tex_x);
			my_pixel_put(&render_img, pxl_horizontal, pxl_vertical, color);
		}
		pxl_vertical++;
	}
}
