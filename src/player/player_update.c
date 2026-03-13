/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:15:08 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/12 20:15:44 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_update(t_data *d)
{
	if (d->move.forward)
		player_move_forward(d);
	if (d->move.backward)
		player_move_backward(d);
	if (d->move.strafe_left)
		player_strafe_left(d);
	if (d->move.strafe_right)
		player_strafe_right(d);
	if (d->move.turn_left)
		player_rotate(d, -ROT_SPEED);
	if (d->move.turn_right)
		player_rotate(d, ROT_SPEED);
	camera_init(&d->map);
}
