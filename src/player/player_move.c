/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:20:00 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/12 21:04:50 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	hits_wall_radius(t_map *m, double x, double y)
{
	double	r;

	r = ((double)MINIMAP_PLAYER_SIZE / 2.0) / MINIMAP_TILE;
	if (is_wall(m, x - r, y - r))
		return (1);
	if (is_wall(m, x + r, y - r))
		return (1);
	if (is_wall(m, x - r, y + r))
		return (1);
	if (is_wall(m, x + r, y + r))
		return (1);
	return (0);
}

void	player_move_forward(t_data *d)
{
	double	next_x;
	double	next_y;

	next_x = d->map.player_x + d->map.dir_x * MOVE_SPEED;
	next_y = d->map.player_y + d->map.dir_y * MOVE_SPEED;
	if (!hits_wall_radius(&d->map, next_x, d->map.player_y))
		d->map.player_x = next_x;
	if (!hits_wall_radius(&d->map, d->map.player_x, next_y))
		d->map.player_y = next_y;
}

void	player_move_backward(t_data *d)
{
	double	next_x;
	double	next_y;

	next_x = d->map.player_x - d->map.dir_x * MOVE_SPEED;
	next_y = d->map.player_y - d->map.dir_y * MOVE_SPEED;
	if (!hits_wall_radius(&d->map, next_x, d->map.player_y))
		d->map.player_x = next_x;
	if (!hits_wall_radius(&d->map, d->map.player_x, next_y))
		d->map.player_y = next_y;
}

void	player_strafe_left(t_data *d)
{
	double	next_x;
	double	next_y;

	next_x = d->map.player_x + d->map.dir_y * MOVE_SPEED;
	next_y = d->map.player_y - d->map.dir_x * MOVE_SPEED;
	if (!hits_wall_radius(&d->map, next_x, d->map.player_y))
		d->map.player_x = next_x;
	if (!hits_wall_radius(&d->map, d->map.player_x, next_y))
		d->map.player_y = next_y;
}

void	player_strafe_right(t_data *d)
{
	double	next_x;
	double	next_y;

	next_x = d->map.player_x - d->map.dir_y * MOVE_SPEED;
	next_y = d->map.player_y + d->map.dir_x * MOVE_SPEED;
	if (!hits_wall_radius(&d->map, next_x, d->map.player_y))
		d->map.player_x = next_x;
	if (!hits_wall_radius(&d->map, d->map.player_x, next_y))
		d->map.player_y = next_y;
}
