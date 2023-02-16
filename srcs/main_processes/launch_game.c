#include "cub3d.h"

static t_player	initialize(t_player pos, int i, int j, char c)
{
	pos.pxl_x = j * SQ_SIZE + (SQ_SIZE / 2);
	pos.pxl_y = i * SQ_SIZE + (SQ_SIZE / 2);
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

static t_player	initialize_player_position(t_player player, char **mat)
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
				player = initialize(player, i, j, mat[i][j]);
				trigger++;
			}
			j++;
		}
		i++;
	}
	return (player);
}

void	launch_game(t_all *game_struct)
{
	game_struct->player = initialize_player_position(game_struct->player, \
		game_struct->mat);
	cast_rays(*game_struct);
	display_minimap(*game_struct);
	mlx_hook(game_struct->window.win_ptr, KeyPress, KeyPressMask,
		movement_management, game_struct);
}
