/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state_controller.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:11:28 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/08 02:39:02 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./game_state_controller.h"
#include "../game_controller/game_controller.h"
#include "../screen_controller/screen_controller.h"

void	add_player_to_screen_buff(t_game *game, t_screen *screen)
{
	add_image_to_buff(screen, game->player->current_image, game->player->position);
}

void	add_walls_to_screen_buff(t_game *game, t_screen *screen)
{
	t_node			*current_node;
	t_game_object	*current_wall;

	current_node = game->walls->head;
	while (current_node)
	{
		current_wall = (t_game_object *) current_node->data;
		add_image_to_buff(screen, current_wall->current_image, current_wall->position);
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
		add_image_to_buff(screen, current_floor->current_image,
			current_floor->position);
		current_node = current_node->next;
	}
}

void	add_enemies_to_screen_buff(t_game *game, t_screen *screen)
{
	t_node			*current_node;
	t_game_object	*current_enemy;

	current_node = game->enemies->head;
	while (current_node)
	{
		current_enemy = (t_game_object *) current_node->data;
		add_image_to_buff(screen, current_enemy->current_image,
			current_enemy->position);
		current_node = current_node->next;
	}
}

int	game_loop(t_game_state *game_state)
{
	check_player_collisions(game_state->game);
	check_enemies_collisions(game_state->game);
	if(game_state->step_counter == 0)
	{
		update_game(game_state->game);
		game_state->step_counter = STEP;
	}
	add_floors_to_screen_buff(game_state->game, game_state->screen);
	add_walls_to_screen_buff(game_state->game, game_state->screen);
	add_player_to_screen_buff(game_state->game, game_state->screen);
	add_enemies_to_screen_buff(game_state->game, game_state->screen);
	draw_screen_buff(game_state->screen);
	print_moves(game_state->screen, "Total moves: ", 0);
	game_state->step_counter --;
}
