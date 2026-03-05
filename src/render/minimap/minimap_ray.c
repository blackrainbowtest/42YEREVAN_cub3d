/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:33:57 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/04 22:17:41 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap_ray(t_data *d)
{
	double	x;
	double	y;
	double	dist;
	t_line	l;

	x = d->map.player_x;
	y = d->map.player_y;
	dist = 0.0;
	while (dist < RAY_MAX_DIST && !is_wall(&d->map, x, y))
	{
		x += d->map.dir_x * RAY_STEP;
		y += d->map.dir_y * RAY_STEP;
		dist += RAY_STEP;
	}
	l.x0 = MINIMAP_X + d->map.player_x * MINIMAP_TILE;
	l.y0 = MINIMAP_Y + d->map.player_y * MINIMAP_TILE;
	l.x1 = MINIMAP_X + x * MINIMAP_TILE;
	l.y1 = MINIMAP_Y + y * MINIMAP_TILE;
	l.color = MAP_COLOR_RYCT;
	draw_line(d, l);
}
