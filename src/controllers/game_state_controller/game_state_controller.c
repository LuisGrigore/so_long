/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state_controller.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:11:28 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/06 17:14:03 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./game_state_controller.h"
#include "../game_controller/game_controller.h"

void	add_player_to_screen_buff(t_game *game, t_screen *screen)
{
	add_image_to_buff(screen, game->player->image, game->player->position);
}

void	add_walls_to_screen_buff(t_game *game, t_screen *screen)
{
	t_node			*current_node;
	t_game_object	*current_wall;

	current_node = game->walls->head;
	while (current_node)
	{
		current_wall = (t_game_object *) current_node->data;
		add_image_to_buff(screen, current_wall->image, current_wall->position);
		current_node = current_node->next;
	}
}

void	add_floors_to_screen_buff(t_game *game, t_screen *screen)
{
	t_node			*current_node;
	t_game_object	*current_floor;

	current_node = game->floors->head;
	while (current_node)
	{
		current_floor = (t_game_object *) current_node->data;
		add_image_to_buff(screen, current_floor->image,
			current_floor->position);
		current_node = current_node->next;
	}
}

int	game_loop(t_game_state *game_state)
{
	add_floors_to_screen_buff(game_state->game, game_state->screen);
	add_walls_to_screen_buff(game_state->game, game_state->screen);
	add_player_to_screen_buff(game_state->game, game_state->screen);
	draw_screen_buff(game_state->screen);
}
