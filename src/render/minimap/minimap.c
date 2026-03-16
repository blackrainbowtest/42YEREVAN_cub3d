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

static void	draw_player_marker(t_data *d, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_PLAYER_SIZE)
	{
		j = 0;
		while (j < MINIMAP_PLAYER_SIZE)
		{
			ft_put_pixel(&d->img, x + j, y + i, MAP_COLOR_PLYR);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_data *d)
{
	draw_map_tiles(d);
	draw_player_minimap(d);
	draw_player_direction(d);
	draw_minimap_rays(d);
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
				draw_tile_with_border(d, screen_x, screen_y, MAP_COLOR_WALL);
			else
				draw_tile_with_border(d, screen_x, screen_y, MAP_COLOR_ELSE);
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
	px -= MINIMAP_PLAYER_SIZE / 2;
	py -= MINIMAP_PLAYER_SIZE / 2;
	draw_player_marker(d, px, py);
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
