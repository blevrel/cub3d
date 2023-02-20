#include "cub3d.h"

int	get_map_height(int fd)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd, 1);
	if (!line)
	{
		ft_print_error("\e[5;31m[ERROR]\e[0m\n");
		ft_print_error("\e[95mCheck scene file\e[0m\n");
		close(fd);
		return (0);
	}
	while (line)
	{
		if (ft_strcmp(line, "\n") != 0)
			count++;
		free(line);
		line = get_next_line(fd, 1);
	}
	if (close(fd) == -1)
		return (0);
	return (count);
}

int	get_map_width(char **mat)
{
	int	i;
	int	max_width;
	int	tmp;

	i = 1;
	if (!mat)
		return (0);
	max_width = ft_strlen(mat[0]);
	while (mat[i])
	{
		tmp = ft_strlen(mat[i]);
		if (tmp > max_width)
			max_width = tmp;
		i++;
	}
	return (max_width);
}

int	convert_rgb_to_hexa(int *color)
{
	char	*nb_r;
	char	*nb_g;
	char	*nb_b;
	char	*res_tmp;
	int		res;
	
	nb_r = ft_itoa_base(color[0], 16);
	res_tmp = ft_itoa_base(color[1], 16);
	nb_b = ft_itoa_base(color[2], 16);
	nb_g = ft_strjoin(nb_r, res_tmp);
	free(res_tmp);
	res_tmp = ft_strjoin(nb_g, nb_b);
	free(nb_r);
	free(nb_b);
	free(nb_g);
	res = ft_atoi_base(res_tmp, "0123456789ABCDEF");
	free(res_tmp);
	return (res);
}
