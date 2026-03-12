/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:14:38 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/10 21:43:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
/* ************************************************************************** */
/*                                                                            */
/*                               main defines                                 */
/*                                                                            */
/* ************************************************************************** */
# define ERROR					1
# define WINDOW_WIDTH			1280
# define WINDOW_HEIGHT			720
# define RAY_STEP				0.02
# define RAY_MAX_DIST			20.0
# define PI						3.14159265358979323846
# define DEG_TO_RAD				0.017453292519943295
# define SCENE_FOV				66.0
# define MOVE_SPEED				0.02
# define ROT_SPEED				0.02
/* ************************************************************************** */
/*                            minimap variables                               */
/* ************************************************************************** */
# define MINIMAP_TILE			64
# define MINIMAP_PLAYER_SIZE	32
# define MINIMAP_X				10
# define MINIMAP_Y				10
# define MINIMAP_FOV 			66.0
# define MINIMAP_RAYS 			120
/* ************************************************************************** */
/*                               map types                                    */
/* ************************************************************************** */
# define ICN_WALL				'1'
# define ICN_GROUND				'0'
# define ICN_PLAYER				'N'
/* ************************************************************************** */
/*                               map colors                                   */
/* ************************************************************************** */
# define MAP_COLOR_WALL			0x00FFFFFF
# define MAP_COLOR_ELSE			0x00333333
# define MAP_COLOR_GRID			0x00555555
# define MAP_COLOR_PLYR			0x00FF0000
# define MAP_COLOR_PLDR			0x00FFFF00
# define MAP_COLOR_RYCT			0x0000FF00
/* ************************************************************************** */
/*                             scene colors                                   */
/* ************************************************************************** */
# define CEILING_COLOR			0x0087CEEB
# define FLOOR_COLOR			0x00444444
# define WALL_NORTH_COLOR		0x00FF4444
# define WALL_SOUTH_COLOR		0x0044FF44
# define WALL_EAST_COLOR		0x004444FF
# define WALL_WEST_COLOR		0x00FFFF44
/* ************************************************************************** */
/*                               keycodes Linux                               */
/* ************************************************************************** */
# define KEY_ESC				65307
# define EV_KEYDOWN				2
# define EV_KEYUP				3
# define EV_DESTROY				17
# define KEY_A					97
# define KEY_D					100
# define KEY_W					119
# define KEY_S					115
# define KEY_AR_L				65361
# define KEY_AR_R				65363
# define KEY_AR_T				65362
# define KEY_AR_B				65364
/* ************************************************************************** */
/*                               structures                                   */
/* ************************************************************************** */
typedef struct s_move
{
	int		forward;
	int		backward;
	int		strafe_left;
	int		strafe_right;
	int		turn_left;
	int		turn_right;
}	t_move;

typedef struct s_dda
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	double	dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
}	t_dda;

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

typedef struct s_tex
{
	void	*img;
	char	*addr;

	int		width;
	int		height;

	int		bpp;
	int		line_len;
	int		endian;
}	t_tex;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;

	double	player_x;
	double	player_y;

	double	dir_x;
	double	dir_y;

	int		floor_color;
	int		ceil_color;

	char	*tex_path_no;
	char	*tex_path_so;
	char	*tex_path_we;
	char	*tex_path_ea;
}	t_map;

typedef struct s_line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	color;
}	t_line;

enum e_tex
{
	TEX_NO = 0,
	TEX_SO = 1,
	TEX_WE = 2,
	TEX_EA = 3,
	TEX_COUNT = 4
};

typedef struct s_data
{
	t_mlx	mlx;
	t_img	img;
	t_map	map;
	t_tex	tex[TEX_COUNT];

	int		exit_code;
	t_move	move;
}	t_data;

/* ************************************************************************** */
/*                                                                            */
/*                               cub3d API                                    */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*     src/engine/raycast     raycast_dda .c                                  */
/* ************************************************************************** */
void		raycast_dda(t_data *d, double dir_x, double dir_y, t_dda *r);

/* ************************************************************************** */
/*     src/engine/raycast     raycast_cast .c                                 */
/* ************************************************************************** */
void		cast_dda(t_data *d, t_dda *r);

/* ************************************************************************** */
/*     src/engine/raycast     raycast_init .c                                 */
/* ************************************************************************** */
void		init_dda(t_data *d, double dir_x, double dir_y, t_dda *r);

/* ************************************************************************** */
/*     src/hooks              hooks .c                                        */
/* ************************************************************************** */
int			on_keydown(int keycode, void *param);
int			on_keyup(int keycode, void *param);
int			on_destroy(void *param);

/* ************************************************************************** */
/*     src/init              init.c                                           */
/* ************************************************************************** */
int			app_init(t_data *d);

/* ************************************************************************** */
/*     src/loader            init.c                                           */
/* ************************************************************************** */
int			load_textures(t_data *d);

/* ************************************************************************** */
/*     src/map                  map_query.c                                   */
/* ************************************************************************** */
int			is_wall(t_map *m, double x, double y);

/* ************************************************************************** */
/*     src/map                  map_stub.c                                    */
/* ************************************************************************** */
int			map_load_stub(t_map *map);

/* ************************************************************************** */
/*     src/player            player_move.c                                    */
/* ************************************************************************** */
void		player_move_forward(t_data *d);
void		player_move_backward(t_data *d);
void		player_strafe_left(t_data *d);
void		player_strafe_right(t_data *d);
void		player_rotate(t_data *d, double angle);
void		player_update(t_data *d);

/* ************************************************************************** */
/*     src/render               render.c                                      */
/* ************************************************************************** */
void		ft_put_pixel(t_img *img, int x, int y, int color);
int			render_frame(void *param);

/* ************************************************************************** */
/*     src/render         render_walls.c                                      */
/* ************************************************************************** */
void		render_wall_column(t_data *d, int x);
void		draw_wall_column(t_data *d, int x, t_dda *r);
void		draw_column_pixels(t_data *d, int x, int start, int end, t_dda *r);

/* ************************************************************************** */
/*     src/render         render_scene.c                                      */
/* ************************************************************************** */
void		render_scene(t_data *d);

/* ************************************************************************** */
/*     src/render/minimap      minimap_player_pos.c                           */
/* ************************************************************************** */
void		get_player_minimap_pos(t_data *d, int *x, int *y);

/* ************************************************************************** */
/*     src/render/minimap      minimap_utils.c                                */
/* ************************************************************************** */
void		draw_square(t_data *d, int x, int y, int color);
void		draw_tile_with_border(t_data *d, int x, int y, int fill_color,
				int border_color);

/* ************************************************************************** */
/*     src/render/minimap      minimap.c                                      */
/* ************************************************************************** */
void		draw_minimap(t_data *d);
void		draw_map_tiles(t_data *d);
void		draw_player_minimap(t_data *d);
void		draw_player_direction(t_data *d);
void		draw_line(t_data *d, t_line l);

/* ************************************************************************** */
/*     src/render/minimap      minimap_ray.c                                  */
/* ************************************************************************** */
void		draw_minimap_rays(t_data *d);

/* ************************************************************************** */
/*     src/utils                    exit.c                                    */
/* ************************************************************************** */
int			clean_exit(t_data *d, int code);


#endif	//CUB3D_H
