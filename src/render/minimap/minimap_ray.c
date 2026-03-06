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

static void	get_ray_hit(t_data *d, double *x, double *y)
{
	double	dist;

	dist = 0.0;
	while (dist < RAY_MAX_DIST && !is_wall(&d->map, *x, *y))
	{
		*x += d->map.dir_x * RAY_STEP;
		*y += d->map.dir_y * RAY_STEP;
		dist += RAY_STEP;
	}
}

void	draw_minimap_ray(t_data *d)
{
	double	x;
	double	y;
	int		x0;
	int		y0;
	t_line	l;

	x = d->map.player_x;
	y = d->map.player_y;
	get_ray_hit(d, &x, &y);
	get_player_minimap_pos(d, &x0, &y0);
	l.x0 = x0;
	l.y0 = y0;
	l.x1 = MINIMAP_X + x * MINIMAP_TILE;
	l.y1 = MINIMAP_Y + y * MINIMAP_TILE;
	l.color = MAP_COLOR_RYCT;
	draw_line(d, l);
}
