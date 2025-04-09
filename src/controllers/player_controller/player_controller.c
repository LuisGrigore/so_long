/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:48:16 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/09 03:41:29 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./player_controller.h"


void update_player(t_game_object *player)
{
	displace(player, 1);
}

void	move_player(t_game_object *player, t_vector2 distance)
{
	if((player->displacement.x != 0) || (player->displacement.y != 0))
		player->can_move = get_can_move(0,0,0,0);
	if (distance.y < 0 && !can_move_up(player))
		return ;
	if (distance.y > 0 && !can_move_down(player))
		return ;
	if (distance.x < 0 && !can_move_left(player))
		return ;
	if (distance.x > 0 && !can_move_right(player))
		return ;
	player->displacement = distance;
}
