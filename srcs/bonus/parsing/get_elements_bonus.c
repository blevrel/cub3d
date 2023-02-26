#include "cub3d_bonus.h"

int	fill_color_elements(char **col_value,
	t_texture_color_data *texture_color_data, int trigger)
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
			texture_color_data->c_color[i] = res;
		if (trigger == 0)
			texture_color_data->f_color[i] = res;
		i++;
	}
	return (0);
}

int	get_color_elements(t_texture_color_data *texture_color_data,
	char **line, int trigger)
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
	if (fill_color_elements(color_value, texture_color_data, trigger) == -1)
	{
		free_double_tab(color_value);
		free_double_tab(line);
		return (-1);
	}
	free_double_tab(color_value);
	return (0);
}

void	fill_texture_elements(t_texture_color_data *texture_color_data,
		char **line)
{
	if (ft_strcmp(line[0], "NO") == 0)
		texture_color_data->no_texture = ft_strdup(line[1]);
	if (ft_strcmp(line[0], "SO") == 0)
		texture_color_data->so_texture = ft_strdup(line[1]);
	if (ft_strcmp(line[0], "WE") == 0)
		texture_color_data->we_texture = ft_strdup(line[1]);
	if (ft_strcmp(line[0], "EA") == 0)
		texture_color_data->ea_texture = ft_strdup(line[1]);
	if (ft_strcmp(line[0], "S1") == 0)
		texture_color_data->s_one_sprite = ft_strdup(line[1]);
	if (ft_strcmp(line[0], "S2") == 0)
		texture_color_data->s_two_sprite = ft_strdup(line[1]);
	if (ft_strcmp(line[0], "S3") == 0)
		texture_color_data->s_three_sprite = ft_strdup(line[1]);
	if (ft_strcmp(line[0], "S4") == 0)
		texture_color_data->s_four_sprite = ft_strdup(line[1]);
	if (ft_strcmp(line[0], "S5") == 0)
		texture_color_data->s_five_sprite = ft_strdup(line[1]);
	if (ft_strcmp(line[0], "S6") == 0)
		texture_color_data->s_six_sprite = ft_strdup(line[1]);
	if (ft_strcmp(line[0], "S7") == 0)
		texture_color_data->s_seven_sprite = ft_strdup(line[1]);
	if (ft_strcmp(line[0], "DOOR") == 0)
		texture_color_data->door_texture = ft_strdup(line[1]);
}
