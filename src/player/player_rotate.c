/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:17:55 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/14 16:20:23 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_rotate(t_data *d, double angle)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cos_a;
	double	sin_a;

	old_dir_x = d->map.dir_x;
	old_plane_x = d->map.plane_x;
	cos_a = cos(angle);
	sin_a = sin(angle);
	d->map.dir_x = d->map.dir_x * cos_a - d->map.dir_y * sin_a;
	d->map.dir_y = old_dir_x * sin_a + d->map.dir_y * cos_a;
	d->map.plane_x = d->map.plane_x * cos_a - d->map.plane_y * sin_a;
	d->map.plane_y = old_plane_x * sin_a + d->map.plane_y * cos_a;
}
