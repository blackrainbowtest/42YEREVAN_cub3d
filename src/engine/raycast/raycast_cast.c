/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_cast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:13:47 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/04 14:12:21 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_wall_cell(t_map *m, int mx, int my)
{
	if (mx < 0 || my < 0 || my >= m->height || mx >= m->width)
		return (1);
	return (m->grid[my][mx] == ICN_WALL);
}

void	cast_dda(t_data *d, t_dda *r)
{
	while (r->dist < RAY_MAX_DIST)
	{
		if (r->side_x < r->side_y)
		{
			r->dist = r->side_x;
			r->side_x += r->delta_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->dist = r->side_y;
			r->side_y += r->delta_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (is_wall_cell(&d->map, r->map_x, r->map_y))
			break ;
	}
	if (r->dist > RAY_MAX_DIST)
		r->dist = RAY_MAX_DIST;
}
