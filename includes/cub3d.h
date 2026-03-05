/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:14:38 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/04 22:08:03 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ************************************************************************** */
/*                                                                            */
/*                               main defines                                 */
/*                                                                            */
/* ************************************************************************** */
# define MLX_ERROR		1
# define WINDOW_WIDTH	400
# define WINDOW_HEIGHT	400
# define MINIMAP_TILE	8
# define RAY_STEP		0.02
# define RAY_MAX_DIST	20.0

# define ICN_WALL		'1'
# define ICN_GROUND		'0'
# define ICN_PLAYER		'P'

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

/* ************************************************************************** */
/*                                                                            */
/*                               keycodes Linux                               */
/*                                                                            */
/* ************************************************************************** */
# define KEY_ESC 65307
# define EV_KEYDOWN 2
# define EV_DESTROY 17
# define KEY_A 97
# define KEY_D 100
# define KEY_W 119
# define KEY_S 115
# define KEY_AR_L 65361
# define KEY_AR_R 65363
# define KEY_AR_T 65362
# define KEY_AR_B 65364
/* ************************************************************************** */
/*                                                                            */
/*                               structures                                   */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		w;
	int		h;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;

	double	player_x;
	double	player_y;

	double	dir_x;
	double	dir_y;
}	t_map;

typedef struct s_line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	color;
}	t_line;

typedef struct s_data
{
	t_mlx	mlx;
	t_img	img;
	t_map	map;

	int		exit_code;
}	t_data;

/* ************************************************************************** */
/*                              render.c (test file)                          */
/* ************************************************************************** */
void		render_test(t_data *d);
/* ************************************************************************** */
/*                                                                            */
/*                               cub3d API                                    */
/*                                                                            */
/* ************************************************************************** */
int			app_init(t_data *d);
int			on_keydown(int keycode, void *param);
int			on_destroy(void *param);
int			clean_exit(t_data *d, int code);
/* ************************************************************************** */
/*                           minimap_utils.c                                  */
/* ************************************************************************** */
static void	draw_square(t_data *d, int x, int y, int color);
/* ************************************************************************** */
/*                              minimap.c                                     */
/* ************************************************************************** */
void		draw_minimap(t_data *d);
void		draw_map_tiles(t_data *d);
void		draw_player_minimap(t_data *d);
void		draw_player_direction(t_data *d);
void		draw_line(t_data *d, t_line l);
/* ************************************************************************** */
/*                              minimap_ray.c                                 */
/* ************************************************************************** */
void		draw_minimap_ray(t_data *d);
/* ************************************************************************** */
/*                              map_query.c                                   */
/* ************************************************************************** */
int			is_wall(t_map *m, double x, double y);
/* ************************************************************************** */
/*                              map_stub .c                                   */
/* ************************************************************************** */
int			map_load_stub(t_map *map);

#endif	//CUB3D_H
