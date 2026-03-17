/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:57:19 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/17 19:00:09 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	texel_at(t_tex *t, int x, int y)
{
	char	*dst;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x >= t->width)
		x = t->width - 1;
	if (y >= t->height)
		y = t->height - 1;
	dst = t->addr + (y * t->line_len + x * (t->bpp / 8));
	return (*(unsigned int *)dst);
}

int	pick_tex_id(t_dda *r)
{
	if (r->side == 0)
	{
		if (r->dir_x > 0)
			return (TEX_WE);
		return (TEX_EA);
	}
	if (r->dir_y > 0)
		return (TEX_NO);
	return (TEX_SO);
}
