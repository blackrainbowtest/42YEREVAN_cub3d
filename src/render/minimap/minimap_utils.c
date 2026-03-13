/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:05:31 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/12 20:05:31 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_data *d, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_TILE)
	{
		j = 0;
		while (j < MINIMAP_TILE)
		{
			ft_put_pixel(&d->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_tile_with_border(t_data *d, int x, int y, int fill_color)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < MINIMAP_TILE)
	{
		j = 0;
		while (j < MINIMAP_TILE)
		{
			color = fill_color;
			if (i == 0 || j == 0 || i == MINIMAP_TILE - 1
				|| j == MINIMAP_TILE - 1)
				color = MAP_COLOR_GRID;
			ft_put_pixel(&d->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
