/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:33:23 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/07 13:35:38 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	char_is_valid(char c)
{
	int		i;
	char	*charset;

	i = 0;
	charset = "NSEW";
	if (c == '0')
		return (FLOOR);
	if (c == '1')
		return (WALL);
	if (ft_isspace(c) == 1)
		return (SPACE);
	if (c == 2)
		return (BORDER);
	while (i < 4)
	{
		if (c == charset[i])
			return (PLAYER);
		i++;
	}
	ft_print_error("\e[5;31m[ERROR]\e[0m\n\e[95mCheck scene file\e[0m\n");
	return (0);
}

bool	closed_walls(char c)
{
	if (ft_isspace(c) || c == 2)
		return (false);
	return (true);
}

bool	check_around(char **mat, int i, int j)
{
	if (!closed_walls(mat[i - 1][j]) || !closed_walls(mat[i][j - 1])
		|| !closed_walls(mat[i][j + 1]) || !closed_walls(mat[i + 1][j]))
	{
		ft_print_error("\e[5;31m[ERROR]\e[0m\n\e[95mCheck scene file\e[0m\n");
		return (false);
	}
	return (true);
}

bool	check_map_content(char **mat, t_map_data *map_data)
{
	int		i;
	int		j;
	bool	value;
	char	c;

	i = 1;
	value = true;
	while (i < map_data->map_height && value != false)
	{
		j = 1;
		while (j < map_data->map_width && value != false)
		{
			c = char_is_valid(mat[i][j]);
			if (c == PLAYER)
				map_data->nb_players++;
			if (c == FLOOR || c == PLAYER)
				value = check_around(mat, i, j);
			j++;
		}
		i++;
	}
	return (value);
}
