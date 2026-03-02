/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:13:47 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/02 19:58:42 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_handler(int keycode, void *param)
{
	(void)param;
	printf("keycode: %d\n", keycode);
	return (0);
}

int	close_handler(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	main(void)
{
	t_data	d;

	d.mlx.w = 800;
	d.mlx.h = 600;
	d.mlx.mlx = mlx_init();
	d.mlx.win = mlx_new_window(d.mlx.mlx, 800, 600, "cub3d");
	d.img.img = mlx_new_image(d.mlx.mlx, d.mlx.w, d.mlx.h);
	d.img.addr = mlx_get_data_addr(d.img.img, &d.img.bpp,
			&d.img.line_len, &d.img.endian);
	render_test(&d);
	mlx_hook(d.mlx.win, EV_KEYDOWN, 1L << 0, key_handler, &d.mlx);
	mlx_hook(d.mlx.win, EV_KEYUP, 0, close_handler, &d.mlx);
	mlx_loop(d.mlx.mlx);
	return (0);
}
