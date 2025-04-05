/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_model.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:16:28 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/05 18:39:28 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_MODEL_H
# define SCREEN_MODEL_H
# include "../../utils/vector2.h"
# include "../image_model/image_model.h"

typedef struct s_screen
{
	void	*mlx;
	void	*mlx_win;
	t_image *buffer;
	t_vector2 size;
}	t_screen;

void	destroy_screen(t_screen *screen);
t_screen	*init_screen(t_vector2 size, char *title);

#endif