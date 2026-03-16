/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:31:02 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/06 17:31:02 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_player_minimap_pos(t_data *d, int *x, int *y)
{
	*x = MINIMAP_X + d->map.player_x * MINIMAP_TILE;
	*y = MINIMAP_Y + d->map.player_y * MINIMAP_TILE;
}
