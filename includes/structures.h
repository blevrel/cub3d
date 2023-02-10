/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:14:15 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/10 10:28:35 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCTURES_H
# define STRUCTURES_H
# include <stdbool.h>

typedef struct s_texture_data
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
}				t_texture_data;

typedef struct s_images_data
{
	char	*no_image;
	char	*so_image;
	char	*we_image;
	char	*ea_image;
}				t_images_data;

typedef struct s_color_data
{
	int	c_color[3];
	int	f_color[3];
}				t_color_data;

typedef struct s_window
{
	void	*win_ptr;
	void	*mlx;	
}				t_window;

typedef struct s_map_data
{
	int	map_width;
	int	map_height;
	int	nb_players;
}				t_map_data;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
	int	pxl_x;
	int	pxl_y;
}				t_player;

typedef struct s_all
{
	t_texture_data		texture_data;
	t_color_data		color_data;
	t_window			window;
	t_map_data			map_data;
	t_images_data		images_data;
	t_player			pos;
}				t_all;

#endif
