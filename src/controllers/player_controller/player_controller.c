/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:48:16 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/08 01:19:26 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./player_controller.h"


void update_player(t_game_object *player)
{

	if(player->displacement.x > 0)
	{
		player->position.x ++;
		player->displacement.x --;
	}
	if(player->displacement.x < 0)
	{
		player->position.x --;
		player->displacement.x ++;
	}
	if(player->displacement.y > 0)
	{
		player->position.y ++;
		player->displacement.y --;
	}
	if(player->displacement.y < 0)
	{
		player->position.y --;
		player->displacement.y ++;
	}
}

void	move_player(t_game_object *player, t_vector2 distance)
{
	if((player->displacement.x != 0) || (player->displacement.y != 0))
		player->can_move = get_can_move(0,0,0,0);
	if (distance.y < 0 && !player->can_move.up)
		return ;
	if (distance.y > 0 && !player->can_move.down)
		return ;
	if (distance.x < 0 && !player->can_move.left)
		return ;
	if (distance.x > 0 && !player->can_move.right)
		return ;
	player->displacement = distance;
}
