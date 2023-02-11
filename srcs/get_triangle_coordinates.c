/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle_coordinates.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:12:50 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/11 17:18:27 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

t_triangle	getTriangleCoords(float angle, t_triangle triangle)
{
  // Convertir l'angle de degrés en radians
	double radian;

	radian = angle * M_PI / 180.0;

  // Calculer les coordonnées du point 1 (coin supérieur gauche du triangle)
	triangle.x_a = 0;
	triangle_y_ = height;

  // Calculer les coordonnées du point 2 (sommet du triangle)
	triangle.x_b = base * cos(radian);
	triangle.y_b = height + base * sin(radian);

  // Calculer les coordonnées du point 3 (coin inférieur droit du triangle)
	triangle.x_c  = base;
	triangle.y_c= height;
	return (triangle);
}
