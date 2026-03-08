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

#include "cub3d.h"

static int	is_spawn_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	set_player_dir(t_map *map, char spawn)
{
	if (spawn == 'N')
	{
		map->dir_x = 0.0;
		map->dir_y = -1.0;
	}
	else if (spawn == 'S')
	{
		map->dir_x = 0.0;
		map->dir_y = 1.0;
	}
	else if (spawn == 'E')
	{
		map->dir_x = 1.0;
		map->dir_y = 0.0;
	}
	else
	{
		map->dir_x = -1.0;
		map->dir_y = 0.0;
	}
}

int	map_load_stub(t_map *map)
{
	static char	*grid[] = {
		"111111",
		"100001",
		"100E01",
		"100001",
		"111111",
		NULL
	};
	int		x;
	int		y;

	map->grid = grid;
	map->width = 6;
	map->height = 5;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (is_spawn_char(grid[y][x]))
			{
				map->player_x = x + 0.5;
				map->player_y = y + 0.5;
				set_player_dir(map, grid[y][x]);
				return (0);
			}
			x++;
		}
		y++;
	}
	map->player_x = 3.0;
	map->player_y = 3.0;
	map->dir_x = 0.0;
	map->dir_y = -1.0;
	return (0);
}
