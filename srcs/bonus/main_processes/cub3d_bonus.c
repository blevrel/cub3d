#include "cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_all	game_struc;

	if (argc != 2)
	{
		ft_print_error("Invalid args. Usage: %s *scene_file*.cub\n", argv[0]);
		return (-1);
	}
	init_struc(&game_struc);
	game_struc.mat = start_parsing(argv[1], &game_struc);
	if (!game_struc.mat)
		return (-2);
	game_struc.window.mlx = mlx_init();
	game_struc.window.win_ptr = open_window(game_struc.window,
			game_struc.texture_color_data, &game_struc.render_data);
	init_images(&game_struc.render_images, game_struc.window);
	launch_game(&game_struc);
	mlx_loop(game_struc.window.mlx);
	free_double_tab(game_struc.mat);
	free_struc_elements(game_struc.texture_color_data);
	mlx_destroy_display(game_struc.window.mlx);
	free(game_struc.window.mlx);
	return (0);
}
