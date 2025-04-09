/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:48:16 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/09 03:03:33 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./enemy_controller.h"
#include "../../models/game_object_model/game_object_model.h"
#include <stdio.h>

void update_enemy(t_game_object *enemy)
{
	if(enemy->can_move.up)
		move_y(enemy, -1);
	if(enemy->can_move.down)
		move_y(enemy, 1);
}
