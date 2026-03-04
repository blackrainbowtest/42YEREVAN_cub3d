/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:13:47 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/04 14:16:16 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	clean_exit(t_data *d, int code)
{
	if (d->img.img && d->mlx.mlx)
		mlx_destroy_image(d->mlx.mlx, d->img.img);
	if (d->mlx.win && d->mlx.mlx)
		mlx_destroy_window(d->mlx.mlx, d->mlx.win);
	exit(code);
	return (0);
}
