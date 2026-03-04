/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:13:47 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/02 19:58:42 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_load_stub(t_map *map)
{
	static char *grid[] = {
		"111111",
		"100001",
		"100001",
		"100001",
		"111111",
		NULL
	};

	// grid = parse_cub();
	map->grid = grid;
	map->width = 6;
	map->height = 5;
	map->player_x = 3.0;
	map->player_y = 3.0;
	map->dir_x = -1.0;
	map->dir_y = 0.0;
	return (0);
}