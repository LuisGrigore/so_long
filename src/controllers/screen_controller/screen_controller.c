/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:04:29 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/06 18:37:20 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./screen_controller.h"
#include <stdlib.h>
#include "../../../minilibx/mlx.h"
#include <stdio.h>
#include "../../utils/utils.h"

t_image	*load_image(t_screen *screen, char *xpm_path)
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(screen->mlx, xpm_path, &width, &height);
	if (!img)
	{
		return (NULL);
	}
	addr = mlx_get_data_addr(img, &bpp, &line_length, &endian);
	if (!addr)
	{
		mlx_destroy_image(screen->mlx, img);
		return (NULL);
	}
	return (init_image(img, addr, bpp, line_length, endian, width, height));
}

void	start_loop(t_screen *screen)
{
	mlx_loop(screen->mlx);
}


void print_moves(t_screen *screen, char *label, int moves)
{
    char *moves_str;
    char *full_str;

    moves_str = ft_itoa(moves);

    full_str = ft_strjoin(label, moves_str);

    mlx_string_put(screen->mlx, screen->mlx_win, 10, screen->size.y, 0xFFFFFF, full_str);

    free(moves_str);
    free(full_str);
}