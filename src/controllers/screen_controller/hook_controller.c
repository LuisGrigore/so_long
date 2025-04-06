/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:06:52 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/06 17:07:00 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./screen_controller.h"
#include "../../../minilibx/mlx.h"

void	set_loop_hook(t_screen *screen, t_hook_funct loop_funct, void *param)
{
	mlx_loop_hook(screen->mlx, loop_funct, param);
}

void	start_loop(t_screen *screen)
{
	mlx_loop(screen->mlx);
}
