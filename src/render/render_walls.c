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

static double	compute_wall_x(t_dda *r)
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
	int	line_height;
	int	draw_start;
	int	draw_end;

	if (r->dist < 0.0001)
		r->dist = 0.0001;
	line_height = (int)(WINDOW_HEIGHT / r->dist);
	draw_start = -line_height / 2 + WINDOW_HEIGHT / 2;
	draw_end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end > WINDOW_HEIGHT)
		draw_end = WINDOW_HEIGHT - 1;
	draw_column_pixels(d, x, draw_start, draw_end, line_height, r);
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

void	draw_column_pixels(t_data *d, int x, int start, int end,
		int line_height, t_dda *r)
{
	int				y;
	int				tex_id;
	t_tex			*t;
	double			wall_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	unsigned int	color;

	y = 0;
	while (y < start)
		ft_put_pixel(&d->img, x, y++, d->map.ceil_color);
	tex_id = pick_tex_id(r);
	t = &d->tex[tex_id];
	if (!t->img || !t->addr || t->width <= 0 || t->height <= 0)
	{
		int flat = get_wall_color(r);
		while (y <= end)
			ft_put_pixel(&d->img, x, y++, flat);
	}
	else
	{
		wall_x = compute_wall_x(r);
		tex_x = (int)(wall_x * (double)t->width);

		if (r->side == 0 && r->dir_x < 0)
			tex_x = t->width - tex_x - 1;
		if (r->side == 1 && r->dir_y > 0)
			tex_x = t->width - tex_x - 1;
		if (line_height <= 0)
			line_height = 1;
		step = (double)t->height / (double)line_height;
		tex_pos = (start - WINDOW_HEIGHT / 2 + line_height / 2.0) * step;
		while (y <= end)
		{
			int tex_y = (int)tex_pos;
			color = texel_at(t, tex_x, tex_y);
			ft_put_pixel(&d->img, x, y++, (int)color);
			tex_pos += step;
		}
	}
	while (y < WINDOW_HEIGHT)
		ft_put_pixel(&d->img, x, y++, d->map.floor_color);
}
