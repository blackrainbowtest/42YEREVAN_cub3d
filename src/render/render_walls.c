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

void	render_wall_column(t_data *d, int x)
{
	double	camera_x;
	double	plane_len;
	double	plane_x;
	double	plane_y;
	double	ray_dir_x;
	double	ray_dir_y;
	t_dda	r;

	camera_x = 2.0 * x / (double)WINDOW_WIDTH - 1.0;
	plane_len = tan((SCENE_FOV * DEG_TO_RAD) / 2.0);
	plane_x = -d->map.dir_y * plane_len;
	plane_y = d->map.dir_x * plane_len;
	ray_dir_x = d->map.dir_x + plane_x * camera_x;
	ray_dir_y = d->map.dir_y + plane_y * camera_x;

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
	draw_column_pixels(d, x, draw_start, draw_end, r);
}

void	draw_column_pixels(t_data *d, int x, int start, int end, t_dda *r)
{
	int	y;
	int	color;

	y = 0;
	while (y < start)
	{
		ft_put_pixel(&d->img, x, y, CEILING_COLOR);
		y++;
	}
	if (r->side == 0)
	{
		if (r->dir_x > 0)
			color = WALL_WEST_COLOR;
		else
			color = WALL_EAST_COLOR;
	}
	else
	{
		if (r->dir_y > 0)
			color = WALL_NORTH_COLOR;
		else
			color = WALL_SOUTH_COLOR;
	}
	while (y <= end)
	{
		ft_put_pixel(&d->img, x, y, color);
		y++;
	}
	while (y < WINDOW_HEIGHT)
	{
		ft_put_pixel(&d->img, x, y, FLOOR_COLOR);
		y++;
	}
}