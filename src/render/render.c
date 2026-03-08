/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:33:57 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/08 16:59:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pixel(t_img *img, int x, int y, int color)
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
	draw_minimap(d);
	mlx_put_image_to_window(d->mlx.mlx, d->mlx.win, d->img.img, 0, 0);
}

int	render_frame(void *param)
{
	t_data	*d;

	d = (t_data *)param;
	player_update(d);
	render_test(d);
	return (0);
}
