/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:48:16 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/06 20:27:12 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./player_controller.h"


void	move_player(t_game_object *player, t_vector2 distance)
{
	if (distance.y < 0 && !player->can_move.up)
		return ;
	if (distance.y > 0 && !player->can_move.down)
		return ;
	if (distance.x < 0 && !player->can_move.left)
		return ;
	if (distance.x > 0 && !player->can_move.right)
		return ;
	player->position = sum_vector2(player->position, distance);
}
