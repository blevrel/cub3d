/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:54:43 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/07 11:43:36 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	fill_color_elements(char **col_value, t_color_data *color_data, int trigger)
{
	int	i;
	int	res;

	i = 0;
	while (i < 3)
	{
		res = ft_atoi(col_value[i]);
		if (res < 0 || res > 255)
			return (-1);
		if (trigger == 1)
			color_data->c_color[i] = res;
		if (trigger == 0)
			color_data->f_color[i] = res;
		i++;
	}
	return (0);
}

int	get_color_elements(t_color_data *color_data, char **line, int trigger)
{
	char	**color_value;

	color_value = ft_split(line[1], ',');
	if (color_value == NULL)
		return (-1);
	if (ft_strlen_double_tab(color_value) != 3)
	{
		free_double_tab(color_value);
		free_double_tab(line);
		return (-1);
	}
	if (fill_color_elements(color_value, color_data, trigger) == -1)
	{
		free_double_tab(color_value);
		free_double_tab(line);
		return (-1);
	}
	free_double_tab(color_value);
	return (0);
}

void	fill_texture_elements(t_texture_data *texture_data, char **line)
{
	if (ft_strcmp(line[0], "NO") == 0)
		texture_data->no_texture = ft_strdup(line[1]);
	if (ft_strcmp(line[0], "SO") == 0)
		texture_data->so_texture = ft_strdup(line[1]);
	if (ft_strcmp(line[0], "WE") == 0)
		texture_data->we_texture = ft_strdup(line[1]);
	if (ft_strcmp(line[0], "EA") == 0)
		texture_data->ea_texture = ft_strdup(line[1]);
}
