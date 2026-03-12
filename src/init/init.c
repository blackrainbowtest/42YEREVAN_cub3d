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

int	app_init(t_data *d)
{
	d->mlx.w = WINDOW_WIDTH;
	d->mlx.h = WINDOW_HEIGHT;
	d->mlx.mlx = mlx_init();
	if (!d->mlx.mlx)
		return (MLX_ERROR);
	d->mlx.win = mlx_new_window(d->mlx.mlx, d->mlx.w, d->mlx.h, "cub3d");
	if (!d->mlx.win)
		return (MLX_ERROR);
	d->img.img = mlx_new_image(d->mlx.mlx, d->mlx.w, d->mlx.h);
	if (!d->img.img)
		return (MLX_ERROR);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bpp,
			&d->img.line_len, &d->img.endian);
	if (!d->img.addr)
		return (MLX_ERROR);
	return (0);
}
