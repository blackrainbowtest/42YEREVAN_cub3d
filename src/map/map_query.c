/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_query.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:13:47 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/12 20:05:47 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_map *m, double x, double y)
{
	int	mx;
	int	my;

	mx = (int)x;
	my = (int)y;
	if (mx < 0 || my < 0 || my >= m->height || mx >= m->width)
		return (1);
	return (m->grid[my][mx] == ICN_WALL);
}
