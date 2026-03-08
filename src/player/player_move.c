/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:20:00 by root              #+#    #+#             */
/*   Updated: 2026/03/08 16:59:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_move_forward(t_data *d)
{
	double	next_x;
	double	next_y;

	next_x = d->map.player_x + d->map.dir_x * MOVE_SPEED;
	next_y = d->map.player_y + d->map.dir_y * MOVE_SPEED;
	if (!is_wall(&d->map, next_x, d->map.player_y))
		d->map.player_x = next_x;
	if (!is_wall(&d->map, d->map.player_x, next_y))
		d->map.player_y = next_y;
}

void	player_move_backward(t_data *d)
{
	double	next_x;
	double	next_y;

	next_x = d->map.player_x - d->map.dir_x * MOVE_SPEED;
	next_y = d->map.player_y - d->map.dir_y * MOVE_SPEED;
	if (!is_wall(&d->map, next_x, d->map.player_y))
		d->map.player_x = next_x;
	if (!is_wall(&d->map, d->map.player_x, next_y))
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
