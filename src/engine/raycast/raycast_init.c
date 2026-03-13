/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:13:47 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/04 14:12:21 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_dda_delta(t_dda *r)
{
	r->delta_x = 1e30;
	r->delta_y = 1e30;
	if (r->dir_x != 0.0)
		r->delta_x = fabs(1.0 / r->dir_x);
	if (r->dir_y != 0.0)
		r->delta_y = fabs(1.0 / r->dir_y);
}

static void	init_dda_steps(t_dda *r)
{
	if (r->dir_x < 0.0)
	{
		r->step_x = -1;
		r->side_x = (r->pos_x - r->map_x) * r->delta_x;
	}
	else
	{
		r->step_x = 1;
		r->side_x = (r->map_x + 1.0 - r->pos_x) * r->delta_x;
	}
	if (r->dir_y < 0.0)
	{
		r->step_y = -1;
		r->side_y = (r->pos_y - r->map_y) * r->delta_y;
	}
	else
	{
		r->step_y = 1;
		r->side_y = (r->map_y + 1.0 - r->pos_y) * r->delta_y;
	}
}

void	init_dda(t_data *d, double dir_x, double dir_y, t_dda *r)
{
	r->pos_x = d->map.player_x;
	r->pos_y = d->map.player_y;
	r->dir_x = dir_x;
	r->dir_y = dir_y;
	r->map_x = (int)r->pos_x;
	r->map_y = (int)r->pos_y;
	init_dda_delta(r);
	init_dda_steps(r);
	r->dist = 0.0;
}
