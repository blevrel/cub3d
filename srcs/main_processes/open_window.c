#include "cub3d.h"

void	*open_window(t_window window)
{
	window.win_ptr = mlx_new_window(window.mlx, WIN_WIDTH,
			WIN_HEIGHT, "cub3D");
	return (window.win_ptr);
}
