/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:06:52 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/06 18:37:55 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./screen_controller.h"
#include "../../../minilibx/mlx.h"

void	set_loop_hook(t_screen *screen, t_hook_funct loop_funct, void *param)
{
	mlx_loop_hook(screen->mlx, loop_funct, param);
}

void	set_key_hook(t_screen *screen, t_hook_funct key_funct, void *param)
{
	mlx_key_hook(screen->mlx_win, key_funct, param);
}

void	set_x_hook(t_screen *screen, t_hook_funct key_funct, void *param)
{
	mlx_hook(screen->mlx_win, 17, 0L, key_funct, param);
}
