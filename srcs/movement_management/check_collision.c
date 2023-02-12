#include "cub3d"

int	get_x_in_mat(float pxl_x, float angle, char *oper1)
{
	float	x;

	x = pxl_x;
	if (!ft_strcmp(oper1, "+cos"))
		x += cos(angle) * MOVESPEED;
	else if (!ft_strcmp(oper1, "-cos"))
		x -= cos(angle) * MOVESPEED;
	else if (!ft_strcmp(oper1, "-sin"))
		x -= sin(angle) * MOVESPEED;
	else if (!ft_strcmp(oper1, "+sin"))
		x += sin(angle) * MOVESPEED;
	return (x / 32);
}

int	get_y_in_mat(float pxl_y, float angle, char *oper2)
{
	float	y;

	y = pxl_y;
	if (!ft_strcmp(oper1, "-sin"))
		y -= sin(angle) * MOVESPEED;
	else if (!ft_strcmp(oper1, "+sin"))
		y += sin(angle) * MOVESPEED;
	else if (!ft_strcmp(oper1, "-cos"))
		y -= cos(angle) * MOVESPEED;
	else if (!ft_strcmp(oper1, "+cos"))
		y += cos(angle) * MOVESPEED;
	return (y / 32);
}

int	check_collision(t_player pos, char **mat, char *oper1, char *oper2)
{
	int	x;
	int	y;

	x = get_x_in_mat(pos.pxl_x, pos.angle, oper1);
	y = get_y_in_mat(pos.pxl_y, pos.angle, oper2);
	if (mat[y][x] == '1')
		return (0);
	return (1);
}
