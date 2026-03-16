/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 00:00:00 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/16 23:29:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	line_steps(t_line l)
{
	int	steps;

	steps = abs(l.x1 - l.x0);
	if (abs(l.y1 - l.y0) > steps)
		steps = abs(l.y1 - l.y0);
	return (steps);
}

static void	draw_line_pixel(t_data *d, double x, double y, int color)
{
	ft_put_pixel(&d->img,
		(int)roundf(x),
		(int)roundf(y),
		color);
}

void	draw_line(t_data *d, t_line l)
{
	int		i;
	int		steps;
	double	pos[2];
	double	inc[2];

	steps = line_steps(l);
	if (steps == 0)
	{
		ft_put_pixel(&d->img, l.x0, l.y0, l.color);
		return ;
	}
	inc[0] = (double)(l.x1 - l.x0) / steps;
	inc[1] = (double)(l.y1 - l.y0) / steps;
	pos[0] = l.x0;
	pos[1] = l.y0;
	i = 0;
	while (i <= steps)
	{
		draw_line_pixel(d, pos[0], pos[1], l.color);
		pos[0] += inc[0];
		pos[1] += inc[1];
		i++;
	}
}
