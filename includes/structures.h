/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:14:15 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/14 09:21:04 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_texture_color_data
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		c_color[3];
	int		f_color[3];
}				t_texture_color_data;

typedef struct s_render_data
{
	void	*no_image;
	void	*so_image;
	void	*we_image;
	void	*ea_image;
	int		c_color;
	int		f_color;
}				t_render_data;

typedef struct s_window
{
	void	*win_ptr;
	void	*mlx;	
}				t_window;

typedef struct s_wall_coords
{
	float	x;
	float	y;
}				t_wall_coords;

typedef struct s_triangle
{
	int	x_a;
	int	y_a;
	int	x_b;
	int	y_b;
	int	x_c;
	int	y_c;
}				t_triangle;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;	
}				t_img_data;

typedef struct s_map_data
{
	int	map_width;
	int	map_height;
	int	nb_players;
}				t_map_data;

typedef struct s_player
{
	float	pxl_x;
	float	pxl_y;
	float	angle;
}				t_player;

typedef struct s_all
{
	t_texture_color_data	texture_color_data;
	t_render_data			render_data;
	t_window				window;
	t_map_data				map_data;
	t_player				pos;
	char					**mat;
}				t_all;

#endif
