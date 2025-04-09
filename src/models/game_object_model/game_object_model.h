/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_object_model.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:21:07 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/09 03:38:14 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OBJECT_MODEL_H
# define GAME_OBJECT_MODEL_H
# include "../../utils/vector2.h"
# include "../../utils/list.h"
# include "../../utils/boolean.h"
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
	t_bool	up;
	t_bool	down;
	t_bool	left;
	t_bool	right;
}	t_can_move;

typedef struct s_game_object
{
	t_vector2			position;
	t_vector2			displacement;
	t_list				*images;
	t_image				*current_image;
	t_can_move			can_move;
	e_game_object_type	type;
}	t_game_object;

t_game_object	*init_game_object(t_list *images, t_vector2 position, t_vector2 displacement, e_game_object_type type, t_can_move can_move);

t_can_move get_can_move(t_bool	up, t_bool	down, t_bool left, t_bool right);
void	restrict_all_movement(t_game_object *game_object);
void	allow_all_movement(t_game_object *game_object);

void	offset_game_object_position(t_game_object *game_object, t_vector2 offset);
void	move_y(t_game_object *game_object, int offset);
void	move_x(t_game_object *game_object, int offset);

void	displace(t_game_object *game_object, unsigned int offset);
void	displace_x(t_game_object *game_object, unsigned int offset);
void	displace_x(t_game_object *game_object, unsigned int offset);

void	set_can_move_up(t_game_object *game_object, t_bool can_move);
void	set_can_move_down(t_game_object *game_object, t_bool can_move);
void	set_can_move_left(t_game_object *game_object, t_bool can_move);
void	set_can_move_right(t_game_object *game_object, t_bool can_move);

t_bool can_move_up(t_game_object *game_object);
t_bool can_move_down(t_game_object *game_object);
t_bool can_move_left(t_game_object *game_object);
t_bool can_move_right(t_game_object *game_object);

#endif
