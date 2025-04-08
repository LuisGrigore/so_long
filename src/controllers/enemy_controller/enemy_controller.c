/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:48:16 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/08 03:08:47 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./enemy_controller.h"
#include <stdio.h>

void update_enemy(t_game_object *enemy)
{
	if(enemy->can_move.up)
		enemy->position.y --;
	if(enemy->can_move.down)
		enemy->position.y ++;
	//printf("%d \n", enemy->can_move.down);
	/*if(enemy->displacement.y == 0 && !enemy->can_move.up)
	{
		enemy->displacement.y = 32;
		enemy->can_move.down = 1;
		enemy->can_move.up = 0;
	}
	else if(enemy->displacement.y == 0 && !enemy->can_move.down)
	{
		enemy->displacement.y = -32;
		enemy->can_move.down = 0;
		enemy->can_move.up = 1;
	}

	if(enemy->can_move.down)
	{
		enemy->displacement.y ++;
		enemy->position.y --;
	}
	
	if(enemy->can_move.up)
	{
		enemy->displacement.y --;
		enemy->position.y ++;
	}*/

}
