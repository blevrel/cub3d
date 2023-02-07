/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:29:42 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/06 17:46:35 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
