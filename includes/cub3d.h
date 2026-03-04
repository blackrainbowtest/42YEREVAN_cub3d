/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:14:38 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/02 20:00:28 by aramarak         ###   ########.fr       */
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
# define EVT_DESTROY 17
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

typedef struct s_data
{
	t_mlx	mlx;
	int		exit_code;
	t_img	img;
}	t_data;

void	render_test(t_data *d);

/* ************************************************************************** */
/*                                                                            */
/*                               cub3d API                                    */
/*                                                                            */
/* ************************************************************************** */

int	ft_app_init(t_data *d);
int	ft_on_keydown(int keycode, void *param);
int	ft_on_destroy(void *param);
int	ft_clean_exit(t_data *d, int code);

#endif	//CUB3D_H
