#include "cub3d.h"

static t_player	initialize(t_player pos, int i, int j, char c)
{
	pos.pxl_x = j * 32 + 16;
	pos.pxl_y = i * 32 + 16;
	if (c == 'W')
		pos.angle = M_PI;
	else if (c == 'E')
		pos.angle = 0;
	else if (c == 'N')
		pos.angle = M_PI / 2;
	else if (c == 'S')
		pos.angle = 3 * M_PI / 2;
	return (pos);
}

static t_player	initialize_player_position(t_player pos, char **mat)
{
	int	i;
	int	j;
	int	trigger;

	i = 1;
	trigger = 0;
	while (!trigger)
	{
		j = 1;
		while (mat[i][j] && !trigger)
		{
			if (mat[i][j] == 'W' || mat[i][j] == 'E'
				|| mat[i][j] == 'N' || mat[i][j] == 'S')
			{
				pos = initialize(pos, i, j, mat[i][j]);
				trigger++;
			}
			j++;
		}
		i++;
	}
	return (pos);
}

void	launch_game(t_all *game_struct)
{
	game_struct->pos = initialize_player_position(game_struct->pos, \
		game_struct->mat);
	display_minimap(game_struct->mat, game_struct->pos, game_struct->window,
		game_struct->map_data);
	mlx_hook(game_struct->window.win_ptr, KeyPress, KeyPressMask,
		movement_management, game_struct);
}
