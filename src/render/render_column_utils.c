/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_column_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:41:43 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/17 20:34:30 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(t_data *d, int x, int *y, int draw_start)
{
	while (*y < draw_start)
		ft_put_pixel(&d->img, x, (*y)++, d->map.ceil_color);
}

void	draw_floor(t_data *d, int x, int y)
{
	while (y < WINDOW_HEIGHT)
		ft_put_pixel(&d->img, x, y++, d->map.floor_color);
}

void	draw_flat_wall(t_data *d, int x, int *y, t_wall_column *col)
{
	while (*y <= col->draw_end)
		ft_put_pixel(&d->img, x, (*y)++, col->color);
}

void	draw_textured_wall(t_data *d, int x, int *y, t_wall_column *col, t_dda *r, t_tex *t)
{
	double			wall_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	unsigned int	color;
	int				tex_y;

	wall_x = compute_wall_x(r);
	tex_x = (int)(wall_x * (double)t->width);
	if (r->side == 0 && r->dir_x < 0)
		tex_x = t->width - tex_x - 1;
	if (r->side == 1 && r->dir_y > 0)
		tex_x = t->width - tex_x - 1;
	if (col->line_height <= 0)
		col->line_height = 1;
	step = (double)t->height / (double)col->line_height;
	tex_pos = (col->draw_start - WINDOW_HEIGHT / 2
			+ col->line_height / 2.0) * step;
	while (*y <= col->draw_end)
	{
		tex_y = (int)tex_pos;
		color = texel_at(t, tex_x, tex_y);
		ft_put_pixel(&d->img, x, (*y)++, (int)color);
		tex_pos += step;
	}
}
