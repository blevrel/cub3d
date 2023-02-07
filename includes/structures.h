/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:14:15 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/06 14:50:47 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCTURES_H
# define STRUCTURES_H
# include <stdbool.h>

//structure contenant toutes les textures des murs
typedef struct s_texture_data
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
}				t_texture_data;

//structure contenant les couleurs du plafond et du sol
typedef struct s_color_data
{
	int	c_color[3];
	int	f_color[3];
}				t_color_data;

typedef struct s_map_data
{
	int	map_width;
	int	map_height;
	int	nb_players;
}				t_map_data;

typedef struct s_all
{
	t_texture_data	texture_data;
	t_color_data	color_data;
	t_map_data		map_data;
}				t_all;

#endif
