/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:14:12 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/09 13:43:01 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./game_controller.h"
#include "../player_controller/player_controller.h"
#include "../enemy_controller/enemy_controller.h"
#include "../../utils/vector2.h"
#include <stdio.h>
#include <errno.h>
#include "./game_object_factory/game_object_factory.h"

void	load_game_objects_from_map(t_game *game, t_image_butch image_butch, int map_fd, int tile_size)
{
	char		c;
	int			read_ret;
	t_vector2	current_pos;

	read_ret = read(map_fd, &c, 1);
	current_pos = get_vector(0, 0);
	while (read_ret == 1)
	{
		game_object_factory(game, image_butch, current_pos, c);
		current_pos.x += tile_size;
		if (c == '\n')
		{
			current_pos.y += tile_size;
			current_pos.x = 0;
		}
		read_ret = read(map_fd, &c, 1);
	}
}

void	check_up(t_game_object *player, t_game_object *wall)
{
	if((wall->position.x == player->position.x) && (player->position.y == wall->position.y + 32))
		set_can_move_up(player, FALSE);
}
void	check_down(t_game_object *player, t_game_object *wall)
{
	if((wall->position.x == player->position.x) && (player->position.y == wall->position.y - 32))
		set_can_move_down(player, FALSE);
}
void	check_left(t_game_object *player, t_game_object *wall)
{
	if((wall->position.y == player->position.y) && (player->position.x == wall->position.x + 32))
		set_can_move_left(player, FALSE);
}

void	check_right(t_game_object *player, t_game_object *wall)
{
	if((wall->position.y == player->position.y) && (player->position.x == wall->position.x - 32))
		set_can_move_right(player, FALSE);
}

void	check_player_collisions(t_game *game)
{
	t_node *current_wall_node = get_walls(game)->head;
	t_game_object *current_wall;
	t_game_object *player = get_player(game);
	
	allow_all_movement(game->player);
	while (current_wall_node)
	{
		current_wall = (t_game_object *) current_wall_node->data;
		check_up(player, current_wall);
		check_down(player, current_wall);
		check_left(player, current_wall);
		check_right(player, current_wall);
		current_wall_node = current_wall_node->next;
	}
}

void	check_enemies_collisions(t_game *game)
{
	t_node *current_wall_node = get_walls(game)->head;
	t_game_object *current_wall;

	t_node *current_enemy_node = get_enemies(game)->head;
	t_game_object *current_enemy;
	while(current_enemy_node)
	{
		current_enemy = (t_game_object *) current_enemy_node->data;
		if (!current_enemy->can_move.up && !current_enemy->can_move.down)
			current_enemy->can_move = get_can_move(1,1,0,0);
		current_enemy_node = current_enemy_node->next;
	}
	current_enemy_node = game->enemies->head;
	while (current_wall_node)
	{
		current_wall = (t_game_object *) current_wall_node->data;
		current_enemy_node = get_enemies(game)->head;
		while(current_enemy_node)
		{
			current_enemy = (t_game_object *) current_enemy_node->data;
			if((current_enemy->position.x == current_wall->position.x) && ((current_enemy->position.y - 32) == current_wall->position.y))
				set_can_move_up(current_enemy, FALSE);	
			if((current_enemy->position.x == current_wall->position.x) && ((current_enemy->position.y + 32) == current_wall->position.y))
				set_can_move_down(current_enemy, FALSE);
			current_enemy_node = current_enemy_node->next;
		}
		current_wall_node = current_wall_node->next;
	}
}


void	update_enemies(t_list *enemies)
{
	t_node *current_node = enemies->head;
	t_game_object *current_enemy;
	
	while(current_node)
	{
		current_enemy = (t_game_object *) current_node->data;
		update_enemy(current_enemy);
		current_node = current_node->next;
	}
}

void	update_game(t_game *game)
{
	update_player(game->player);
	update_enemies(game->enemies);
}