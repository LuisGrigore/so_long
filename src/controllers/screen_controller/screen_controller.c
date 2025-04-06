/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:04:29 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/06 17:06:37 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./screen_controller.h"
#include <stdlib.h>
#include "../../../minilibx/mlx.h"

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
