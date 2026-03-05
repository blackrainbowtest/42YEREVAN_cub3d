/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:33:57 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/04 22:17:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

void	render_test(t_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (y < d->mlx.h)
	{
		x = 0;
		while (x < d->mlx.w)
		{
			ft_put_pixel(&d->img, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(d->mlx.mlx, d->mlx.win, d->img.img, 0, 0);
}
