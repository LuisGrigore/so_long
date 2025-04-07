/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:51:44 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/08 00:42:14 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CONTROLLER_H
# define PLAYER_CONTROLLER_H
# include "../../models/game_object_model/game_object_model.h"

void			move_player(t_game_object *player, t_vector2 velocity);
void update_player(t_game_object *player);

#endif
