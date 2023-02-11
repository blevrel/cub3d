#include "cub3d.h"

static void	initialize(t_all *game_struct, int i, int j, char c)
{
	game_struct->pos.pxl_x = (j - 1) * 64 + 32;
	game_struct->pos.pxl_y = (i - 1) * 64 + 32;
	if (c == 'W')
		game_struct->pos.angle = PI;
	else if (c == 'E')
		game_struct->pos.angle = 0;
	else if (c == 'N')
		game_struct->pos.angle = PI / 2;
	else if (c == 'S')
		game_struct->pos.angle = 3 * PI / 2;
}

static void	initialize_player_position(t_all *game_struct, char **mat)
{
	int	i;
	int	j;

	i = 1;
	while (mat[i])
	{
		j = 1;
		while (mat[i][j])
		{
			if (mat[i][j] == 'W' || mat[i][j] == 'E'
				|| mat[i][j] == 'N' || mat[i][j] == 'S')
			{
				initialize(game_struct, i, j, mat[i][j]);
				break;
			}
			j++;
		}
		i++;
	}
}

void	launch_game(t_all *game_struct, char **mat)
{
	initialize_player_position(game_struct, mat);
	mlx_key_hook(game_struct->window.win_ptr, movement_management, \
		game_struct);
}
