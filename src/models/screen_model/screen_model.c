/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_model.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:31:35 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/06 19:46:21 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./screen_model.h"
#include "../../../minilibx/mlx.h"
#include "../../utils/utils.h"
#include <stdio.h>

t_image	*get_screen_buffe(t_screen *screen)
{
	t_image	*img_grande;

	img_grande = init_image(NULL, NULL, 0, 0, 0, 0, 0);
	img_grande->img = mlx_new_image(screen->mlx, screen->size.x,
			screen->size.y);
	img_grande->addr = mlx_get_data_addr(img_grande->img, &img_grande->bpp,
			&img_grande->line_length, &img_grande->endian);
	img_grande->width = screen->size.x;
	img_grande->height = screen->size.y;
}

t_screen	*init_screen(t_vector2 size, char *title)
{
	t_screen	*screen;

	screen = ft_calloc(1, sizeof(t_screen));
	if (!screen)
		return (NULL);
	screen->mlx = mlx_init();
	if (!screen->mlx)
	{
		destroy_screen(screen);
		return (NULL);
	}
	screen->mlx_win = mlx_new_window(screen->mlx, size.x, size.y, title);
	if (!screen->mlx_win)
	{
		destroy_screen(screen);
		return (NULL);
	}
	screen->size = size;
	screen->buffer = get_screen_buffe(screen);
	if (!screen->buffer)
	{
		destroy_screen(screen);
		return (NULL);
	}
	return (screen);
}

void	destroy_screen(t_screen *screen)
{
	if (!screen)
		return ;
	if (screen->mlx && screen->mlx_win)
		mlx_destroy_window(screen->mlx, screen->mlx_win);
	if (screen->mlx)
		mlx_destroy_display(screen->mlx);
	free(screen);
}
