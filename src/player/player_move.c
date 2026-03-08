/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:20:00 by root              #+#    #+#             */
/*   Updated: 2026/03/08 18:48:12 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	player_collision_radius(void)
{
	return (((double)MINIMAP_PLAYER_SIZE / 2.0) / MINIMAP_TILE);
}

static int	hits_wall_radius(t_map *m, double x, double y)
{
	double	r;

	r = player_collision_radius();
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

void	player_rotate(t_data *d, double angle)
{
	double	old_dir_x;
	double	cos_a;
	double	sin_a;

	old_dir_x = d->map.dir_x;
	cos_a = cos(angle);
	sin_a = sin(angle);
	d->map.dir_x = d->map.dir_x * cos_a - d->map.dir_y * sin_a;
	d->map.dir_y = old_dir_x * sin_a + d->map.dir_y * cos_a;
}

void	player_update(t_data *d)
{
	if (d->move.forward)
		player_move_forward(d);
	if (d->move.backward)
		player_move_backward(d);
	if (d->move.turn_left)
		player_rotate(d, -ROT_SPEED);
	if (d->move.turn_right)
		player_rotate(d, ROT_SPEED);
}
