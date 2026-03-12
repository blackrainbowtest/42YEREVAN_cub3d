/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:13:47 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/04 14:12:21 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	camera_init(t_map *map)
{
	double	plane_len;

	plane_len = tan((SCENE_FOV * DEG_TO_RAD) / 2.0);
	map->plane_x = -map->dir_y * plane_len;
	map->plane_y = map->dir_x * plane_len;
}

int	app_init(t_data *d)
{
	d->mlx.w = WINDOW_WIDTH;
	d->mlx.h = WINDOW_HEIGHT;
	d->mlx.mlx = mlx_init();
	if (!d->mlx.mlx)
		return (ERROR);
	d->mlx.win = mlx_new_window(d->mlx.mlx, d->mlx.w, d->mlx.h, "cub3d");
	if (!d->mlx.win)
		return (ERROR);
	d->img.img = mlx_new_image(d->mlx.mlx, d->mlx.w, d->mlx.h);
	if (!d->img.img)
		return (ERROR);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bpp,
			&d->img.line_len, &d->img.endian);
	if (!d->img.addr)
		return (ERROR);
	camera_init(&d->map);
	return (0);
}
