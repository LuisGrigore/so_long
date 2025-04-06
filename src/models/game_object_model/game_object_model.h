/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_object_model.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:21:07 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/06 20:23:57 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OBJECT_MODEL_H
# define GAME_OBJECT_MODEL_H
# include "../../utils/vector2.h"
# include "../image_model/image_model.h"

typedef enum e_game_object_type
{
	PLAYER,
	MAP,
	COIN,
	ENEMY
}	e_game_object_type;

typedef struct s_can_move
{
	int	up;
	int	down;
	int	left;
	int	right;
}	t_can_move;

typedef struct s_game_object
{
	t_vector2			position;
	t_image				*image;
	t_can_move			can_move;
	e_game_object_type	type;
}	t_game_object;

t_game_object	*init_game_object(t_image *image, t_vector2 position,
					e_game_object_type type, t_can_move can_move);

t_can_move get_can_move(int	up, int	down, int	left, int	right);

#endif
