/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:13:47 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/04 14:18:46 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	on_keydown(int keycode, void *param)
{
	t_data	*d;

	d = (t_data *)param;
	if (keycode == KEY_ESC)
		clean_exit(d, 0);
	if (keycode == KEY_W)
		d->move.forward = 1;
	if (keycode == KEY_S)
		d->move.backward = 1;
	if (keycode == KEY_A)
		d->move.strafe_left = 1;
	if (keycode == KEY_D)
		d->move.strafe_right = 1;
	if (keycode == KEY_AR_L)
		d->move.turn_left = 1;
	if (keycode == KEY_AR_R)
		d->move.turn_right = 1;
	return (0);
}

int	on_keyup(int keycode, void *param)
{
	t_data	*d;

	d = (t_data *)param;
	if (keycode == KEY_W)
		d->move.forward = 0;
	if (keycode == KEY_S)
		d->move.backward = 0;
	if (keycode == KEY_A)
		d->move.strafe_left = 0;
	if (keycode == KEY_D)
		d->move.strafe_right = 0;
	if (keycode == KEY_AR_L)
		d->move.turn_left = 0;
	if (keycode == KEY_AR_R)
		d->move.turn_right = 0;
	return (0);
}

int	on_destroy(void *param)
{
	t_data	*d;

	d = (t_data *)param;
	return (clean_exit(d, 0));
}
