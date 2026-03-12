/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:23:15 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/12 09:35:17 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_textures(t_data *d)
{
	if (load_texture(d, &d->tex[TEX_NO], d->map.tex_path_no))
		return (ERROR);
	if (load_texture(d, &d->tex[TEX_SO], d->map.tex_path_so))
		return (ERROR);
	if (load_texture(d, &d->tex[TEX_WE], d->map.tex_path_we))
		return (ERROR);
	if (load_texture(d, &d->tex[TEX_EA], d->map.tex_path_ea))
		return (ERROR);
	return (0);
}

int	load_texture(t_data *d, t_tex *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(d->mlx.mlx, path,
			&tex->width, &tex->height);
	if (!tex->img)
		return (ERROR);
	tex->addr = mlx_get_data_addr(tex->img,
			&tex->bpp, &tex->line_len, &tex->endian);
	if (!tex->addr)
		return (ERROR);
	return (0);
}
