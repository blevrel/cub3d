#include "cub3d.h"

int	assign_line_to_elem(t_texture_color_data *texture_color_data,
	char *line, int *i)
{
	char	**splitted_line;

	if (!line[0])
		return (-1);
	splitted_line = ft_split(line, ' ');
	free(line);
	if (ft_strlen_double_tab(splitted_line) != 2)
	{
		free_double_tab(splitted_line);
		return (-1);
	}
	fill_texture_elements(texture_color_data, splitted_line);
	if (ft_strcmp(splitted_line[0], "C") == 0)
	{
		if (get_color_elements(texture_color_data, splitted_line, 1) == -1)
			return (-1);
	}
	if (ft_strcmp(splitted_line[0], "F") == 0)
	{
		if (get_color_elements(texture_color_data, splitted_line, 0) == -1)
			return (-1);
	}
	free_double_tab(splitted_line);
	(*i)++;
	return (0);
}

int	skip_textures_and_colors(char *scene_file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(scene_file, O_RDONLY);
	i = 0;
	if (fd == -1)
		return (-1);
	while (i < 6)
	{
		line = get_next_line(fd, 1);
		if (ft_strcmp(line, "\n") != 0)
		{
			free(line);
			i++;
		}
		else
			free(line);
	}
	return (fd);
}

char	*trim_end_of_line(int fd)
{
	char	*line;
	char	*trim_line;

	line = get_next_line(fd, 1);
	if (!line)
	{
		ft_print_error("\e[5;31m[ERROR]\e[0m\n\e[95mCheck scene file\e[0m\n");
		return (NULL);
	}
	trim_line = ft_strtrim(line, "\n");
	if (!trim_line)
		return (NULL);
	free(line);
	return (trim_line);
}

int	init_textures_and_colors(t_texture_color_data *texture_color_data,
		char *scene_file)
{
	int		fd;
	int		i;
	char	*trim_line;

	i = 0;
	fd = open(scene_file, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (i < 6)
	{
		trim_line = trim_end_of_line(fd);
		if (!trim_line)
			return (-1);
		if (!trim_line[0])
			free(trim_line);
		else if (assign_line_to_elem(texture_color_data, trim_line
				, &i) == -1)
		{
			ft_print_error("\e[5;31m[ERROR]\e[0m\n\e[95mCheck scene file\e[0m\n");
			return (-1);
		}
	}
	return (fd);
}
