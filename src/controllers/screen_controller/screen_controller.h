/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_controller.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:09:31 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/06 19:06:23 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_CONTROLLER_H
# define SCREEN_CONTROLLER_H
# include "../../models/screen_model/screen_model.h"
# include "../../models/image_model/image_model.h"
# include "../../utils/t_hook_funct.h"

t_image	*load_image(t_screen *screen, char *xpm_path);
void	add_image_to_buff(t_screen *screen, t_image *img, t_vector2 position);
void	draw_screen_buff(t_screen *screen);
void	set_loop_hook(t_screen *screen, t_hook_funct loop_funct, void *param);
void	set_x_hook(t_screen *screen, t_hook_funct key_funct, void *param);
void	set_key_hook(t_screen *screen, t_hook_funct key_funct, void *param);
void	start_loop(t_screen *screen);

#endif
