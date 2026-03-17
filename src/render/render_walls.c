/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:13:47 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/04 14:12:21 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	compute_wall_x(t_dda *r)
{
	double	wall_x;

	if (r->side == 0)
		wall_x = r->pos_y + r->dist * r->dir_y;
	else
		wall_x = r->pos_x + r->dist * r->dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

void	render_wall_column(t_data *d, int x)
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	t_dda	r;

	camera_x = 2.0 * x / (double)WINDOW_WIDTH - 1.0;
	ray_dir_x = d->map.dir_x + d->map.plane_x * camera_x;
	ray_dir_y = d->map.dir_y + d->map.plane_y * camera_x;
	raycast_dda(d, ray_dir_x, ray_dir_y, &r);
	draw_wall_column(d, x, &r);
}

void	draw_wall_column(t_data *d, int x, t_dda *r)
{
	t_wall_column	col;

	if (r->dist < 0.0001)
		r->dist = 0.0001;
	col.line_height = (int)(WINDOW_HEIGHT / r->dist);
	col.draw_start = -col.line_height / 2 + WINDOW_HEIGHT / 2;
	col.draw_end = col.line_height / 2 + WINDOW_HEIGHT / 2;
	if (col.draw_start < 0)
		col.draw_start = 0;
	if (col.draw_end > WINDOW_HEIGHT)
		col.draw_end = WINDOW_HEIGHT - 1;
	col.color = 0;
	draw_column_pixels(d, x, &col, r);
}

static int	get_wall_color(t_dda *r)
{
	if (r->side == 0)
	{
		if (r->dir_x > 0)
			return (WALL_WEST_COLOR);
		else
			return (WALL_EAST_COLOR);
	}
	else
	{
		if (r->dir_y > 0)
			return (WALL_NORTH_COLOR);
		else
			return (WALL_SOUTH_COLOR);
	}
}

void	draw_column_pixels(t_data *d, int x, t_wall_column *col, t_dda *r)
{
	int				y;
	int				tex_id;
	t_tex			*t;

	y = 0;
	tex_id = pick_tex_id(r);
	t = &d->tex[tex_id];
	draw_ceiling(d, x, &y, col->draw_start);
	if (!t->img || !t->addr || t->width <= 0 || t->height <= 0)
	{
		col->color = get_wall_color(r);
		draw_flat_wall(d, x, &y, col);
	}
	else
	{
		draw_textured_wall(d, x, &y, col, r, t);
	}
	draw_floor(d, x, y);
}
