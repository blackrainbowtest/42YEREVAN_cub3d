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

static void	get_ray_hit(t_data *d, double *x, double *y,
		double dir_x, double dir_y)
{
	double	dist;

	dist = 0.0;
	while (dist < RAY_MAX_DIST && !is_wall(&d->map, *x, *y))
	{
		*x += dir_x * RAY_STEP;
		*y += dir_y * RAY_STEP;
		dist += RAY_STEP;
	}
}

static void	draw_single_ray(t_data *d, double dir_x, double dir_y)
{
	double	x;
	double	y;
	int		x0;
	int		y0;
	t_line	l;

	x = d->map.player_x;
	y = d->map.player_y;
	get_ray_hit(d, &x, &y, dir_x, dir_y);
	get_player_minimap_pos(d, &x0, &y0);
	l.x0 = x0;
	l.y0 = y0;
	l.x1 = MINIMAP_X + x * MINIMAP_TILE + MINIMAP_TILE / 2;
	l.y1 = MINIMAP_Y + y * MINIMAP_TILE + MINIMAP_TILE / 2;
	l.color = MAP_COLOR_RYCT;
	draw_line(d, l);
}

static void	draw_minimap_rays_loop(t_data *d)
{
	double	player_angle;
	double	fov_rad;
	double	angle;
	double	angle_step;
	int		i;

	if (MINIMAP_RAYS <= 1)
	{
		draw_single_ray(d, d->map.dir_x, d->map.dir_y);
		return ;
	}
	player_angle = atan2(d->map.dir_y, d->map.dir_x);
	fov_rad = MINIMAP_FOV * DEG_TO_RAD;
	angle = player_angle - (fov_rad / 2.0);
	angle_step = fov_rad / (MINIMAP_RAYS - 1);
	i = 0;
	while (i < MINIMAP_RAYS)
	{
		draw_single_ray(d, cos(angle), sin(angle));
		angle += angle_step;
		i++;
	}
}

void	draw_minimap_rays(t_data *d)
{
	draw_minimap_rays_loop(d);
}
