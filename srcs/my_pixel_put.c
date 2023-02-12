#include "cub3d.h"

void	my_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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
