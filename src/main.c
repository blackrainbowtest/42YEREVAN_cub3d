/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:13:47 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/12 20:08:47 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	register_hooks(t_data *d)
{
	mlx_hook(d->mlx.win, EV_KEYDOWN, 1L << 0, on_keydown, d);
	mlx_hook(d->mlx.win, EV_KEYUP, 1L << 1, on_keyup, d);
	mlx_hook(d->mlx.win, EV_DESTROY, 0, on_destroy, d);
	mlx_loop_hook(d->mlx.mlx, render_frame, d);
}

int	main(void)
{
	t_data	d;

	ft_memset(&d, 0, sizeof(d));
	if (app_init(&d) != 0)
		return (ERROR);
	if (map_load_stub(&d.map) != 0)
		return (ERROR);
	camera_init(&d.map);
	if (load_textures(&d) != 0)
		return (clean_exit(&d, ERROR));
	register_hooks(&d);
	mlx_loop(d.mlx.mlx);
	return (0);
}
