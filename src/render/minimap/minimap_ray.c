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

static int	is_wall_cell(t_map *m, int mx, int my)
{
	if (mx < 0 || my < 0 || my >= m->height || mx >= m->width)
		return (1);
	return (m->grid[my][mx] == ICN_WALL);
}

static void	init_dda(t_data *d, double dir_x, double dir_y, t_dda *r)
{
	r->pos_x = d->map.player_x;
	r->pos_y = d->map.player_y;
	r->dir_x = dir_x;
	r->dir_y = dir_y;
	r->map_x = (int)r->pos_x;
	r->map_y = (int)r->pos_y;
	r->delta_x = 1e30;
	r->delta_y = 1e30;
	if (dir_x != 0.0)
		r->delta_x = fabs(1.0 / dir_x);
	if (dir_y != 0.0)
		r->delta_y = fabs(1.0 / dir_y);
	if (dir_x < 0.0)
	{
		r->step_x = -1;
		r->side_x = (r->pos_x - r->map_x) * r->delta_x;
	}
	else
	{
		r->step_x = 1;
		r->side_x = (r->map_x + 1.0 - r->pos_x) * r->delta_x;
	}
	if (dir_y < 0.0)
	{
		r->step_y = -1;
		r->side_y = (r->pos_y - r->map_y) * r->delta_y;
	}
	else
	{
		r->step_y = 1;
		r->side_y = (r->map_y + 1.0 - r->pos_y) * r->delta_y;
	}
	r->dist = 0.0;
}

static void	cast_dda(t_data *d, t_dda *r)
{
	while (r->dist < RAY_MAX_DIST)
	{
		if (r->side_x < r->side_y)
		{
			r->dist = r->side_x;
			r->side_x += r->delta_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->dist = r->side_y;
			r->side_y += r->delta_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (is_wall_cell(&d->map, r->map_x, r->map_y))
			break ;
	}
	if (r->dist > RAY_MAX_DIST)
		r->dist = RAY_MAX_DIST;
}

static void	get_ray_hit_dda(t_data *d, double dir_x, double dir_y, double hit[2])
{
	t_dda	r;

	init_dda(d, dir_x, dir_y, &r);
	cast_dda(d, &r);
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
}

void	draw_minimap_rays(t_data *d)
{
	draw_minimap_rays_loop(d);
}
