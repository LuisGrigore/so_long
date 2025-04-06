/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_buffer_controller.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:07:11 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/06 20:50:40 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./screen_controller.h"
#include "../../../minilibx/mlx.h"

int	get_pixel_color(t_image *img, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return (0);
	pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	return (*(int *)pixel);
}

void	add_image_to_buff(t_screen *screen, t_image *img, t_vector2 position)
{
	int	i;
	int	j;
	int	color;
	int	pixel_index_grande;
	int	pixel_index_pequena;

	for (i = 0; i < img->height; i++)
	{
		for (j = 0; j < img->width; j++)
		{
			pixel_index_grande = ((position.y + i) * screen->buffer->line_length) + ((position.x + j) * (screen->buffer->bpp / 8));
			if ((position.y + i) < screen->buffer->height && (position.x + j) < screen->buffer->width)
			{
				pixel_index_pequena = (i * img->line_length) + (j * (img->bpp / 8));
				color = *(int *)(img->addr + pixel_index_pequena);
				if (color != -16777216)
				{
					*(int *)(screen->buffer->addr + pixel_index_grande) = color;
				}
			}
		}
	}
}

void	draw_screen_buff(t_screen *screen)
{
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->buffer->img, 0, 0);
}
