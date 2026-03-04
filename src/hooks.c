/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:13:47 by aramarak          #+#    #+#             */
/*   Updated: 2026/03/04 14:18:46 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	on_keydown(int keycode, void *param)
{
	t_data	*d;

	d = (t_data *)param;
	printf("keycode: %d\n", keycode);
	if (keycode == KEY_ESC)
		return (clean_exit(d, 0));
	return (0);
}

int	on_destroy(void *param)
{
	t_data	*d;

	d = (t_data *)param;
	return (clean_exit(d, 0));
}
