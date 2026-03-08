/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:13:47 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/08 16:59:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_data	d;

	if (app_init(&d) != 0)
		return (MLX_ERROR);
	map_load_stub(&d.map);
	mlx_loop_hook(d.mlx.mlx, render_frame, &d);
	mlx_hook(d.mlx.win, EV_KEYDOWN, 1L << 0, on_keydown, &d);
	mlx_hook(d.mlx.win, EV_KEYUP, 1L << 1, on_keyup, &d);
	mlx_hook(d.mlx.win, EV_DESTROY, 0, on_destroy, &d);
	mlx_loop(d.mlx.mlx);
	return (0);
}
