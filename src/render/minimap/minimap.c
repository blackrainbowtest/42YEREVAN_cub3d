/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:33:57 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/05 14:03:16 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_data *d)
{
	draw_map_tiles(d);
	draw_player_minimap(d);
	draw_player_direction(d);
	draw_minimap_ray(d);
}

void	draw_map_tiles(t_data *d)
{
	int	x;
	int	y;
	int	screen_x;
	int	screen_y;

	y = 0;
	while (y < d->map.height)
	{
		x = 0;
		while (x < d->map.width)
		{
			screen_x = MINIMAP_X + x * MINIMAP_TILE;
			screen_y = MINIMAP_Y + y * MINIMAP_TILE;
			if (d->map.grid[y][x] == '1')
				draw_square(d, screen_x, screen_y, MAP_COLOR_WALL);
			else
				draw_square(d, screen_x, screen_y, MAP_COLOR_ELSE);
			x++;
		}
		y++;
	}
}

void	draw_player_minimap(t_data *d)
{
	int	px;
	int	py;

	get_player_minimap_pos(d, &px, &py);
	draw_square(d, px, py, MAP_COLOR_PLYR);
}

void	draw_player_direction(t_data *d)
{
	t_line	line;
	int		length;
	int		x0;
	int		y0;

	length = MINIMAP_TILE * 2;
	get_player_minimap_pos(d, &x0, &y0);
	line.x0 = x0;
	line.y0 = y0;
	line.x1 = x0 + d->map.dir_x * length;
	line.y1 = y0 + d->map.dir_y * length;
	line.color = MAP_COLOR_PLDR;
	draw_line(d, line);
}

void	draw_line(t_data *d, t_line l)
{
	int		i;
	int		steps;
	float	x;
	float	y;
	float	x_inc;
	float	y_inc;

	steps = abs(l.x1 - l.x0);
	if (abs(l.y1 - l.y0) > steps)
		steps = abs(l.y1 - l.y0);
	x_inc = (float)(l.x1 - l.x0) / steps;
	y_inc = (float)(l.y1 - l.y0) / steps;
	x = l.x0;
	y = l.y0;
	i = 0;
	while (i <= steps)
	{
		ft_put_pixel(&d->img, (int)x, (int)y, l.color);
		x += x_inc;
		y += y_inc;
		i++;
	}
}
