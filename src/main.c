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

int	main(void)
{
	t_data	d;

	if (app_init(&d) != 0)
		return (MLX_ERROR);
	render_test(&d);
	mlx_hook(d.mlx.win, EVT_KEYDOWN, 1L << 0, on_keydown, &d);
	mlx_hook(d.mlx.win, EVT_DESTROY, 0, on_destroy, &d);
	mlx_loop(d.mlx.mlx);
	return (0);
}
