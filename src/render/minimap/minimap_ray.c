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

static void	get_ray_hit_dda(t_data *d, double dir_x, double dir_y,
	double hit[2])
{
	t_dda	r;

	raycast_dda(d, dir_x, dir_y, &r);
	hit[0] = r.pos_x + r.dir_x * r.dist;
	hit[1] = r.pos_y + r.dir_y * r.dist;
}

static void	draw_single_ray(t_data *d, double dir_x, double dir_y)
{
	double	hit[2];
	int		x0;
	int		y0;
	t_line	l;

	get_ray_hit_dda(d, dir_x, dir_y, hit);
	get_player_minimap_pos(d, &x0, &y0);
	l.x0 = x0;
	l.y0 = y0;
	l.x1 = MINIMAP_X + hit[0] * MINIMAP_TILE;
	l.y1 = MINIMAP_Y + hit[1] * MINIMAP_TILE;
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
	draw_single_ray(d, d->map.dir_x, d->map.dir_y);
}

void	draw_minimap_rays(t_data *d)
{
	draw_minimap_rays_loop(d);
}
