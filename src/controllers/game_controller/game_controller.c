/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:14:12 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/08 03:28:11 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./game_controller.h"
#include "../player_controller/player_controller.h"
#include "../enemy_controller/enemy_controller.h"
#include "../../utils/vector2.h"
#include <stdio.h>
#include <errno.h>


void	game_object_factory(t_game *game, t_image_butch image_butch,
		t_vector2 position, char c)
{
	t_can_move can_move_player = get_can_move(1,1,1,1);
	t_can_move can_move_rest = get_can_move(0,0,0,0);
	t_list *images;
	
	if (c == 'P')
	{
		images = init_list(sizeof(t_image));
		insert_front(images, image_butch.player_image);
		game->player = init_game_object(images,
				position, get_vector_from_floats(0, 0), PLAYER, can_move_player);
		images = init_list(sizeof(t_image));
		insert_front(images, image_butch.floor_image);
		insert_front(game->floors, init_game_object(images,
				position, get_vector_from_floats(0, 0), MAP, can_move_rest));
	}
	else if (c == '1')
	{
		images = init_list(sizeof(t_image));
		insert_front(images, image_butch.wall_image);
		insert_front(game->walls, init_game_object(images,
				position, get_vector_from_floats(0, 0), MAP, can_move_rest));
	}
	else if (c == '0')
	{
		images = init_list(sizeof(t_image));
		insert_front(images, image_butch.floor_image);
		insert_front(game->floors, init_game_object(images,
				position, get_vector_from_floats(0, 0), MAP, can_move_rest));
	}
	else if (c == 'e')
	{
		images = init_list(sizeof(t_image));
		insert_front(images, image_butch.wall_image);
		insert_front(game->enemies, init_game_object(images,
				position, get_vector_from_floats(0, 0), MAP, get_can_move(1,1,0,0)));
				images = init_list(sizeof(t_image));
		insert_front(images, image_butch.floor_image);
		insert_front(game->floors, init_game_object(images,
				position, get_vector_from_floats(0, 0), MAP, can_move_rest));
	}
}

void	load_game_objects_from_map(t_game *game, t_image_butch image_butch,
		int map_fd, int tile_size)
{
	char		c;
	int			read_ret;
	t_vector2	current_pos;

	read_ret = read(map_fd, &c, 1);
	current_pos = get_vector_from_floats(0, 0);
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
		player->can_move.up = 0;
}
void	check_down(t_game_object *player, t_game_object *wall)
{
	if((wall->position.x == player->position.x) && (player->position.y == wall->position.y - 32))
		player->can_move.down = 0;
}
void	check_left(t_game_object *player, t_game_object *wall)
{
	if((wall->position.y == player->position.y) && (player->position.x == wall->position.x + 32))
		player->can_move.left = 0;
}

void	check_right(t_game_object *player, t_game_object *wall)
{
	if((wall->position.y == player->position.y) && (player->position.x == wall->position.x - 32))
		player->can_move.right = 0;
}

void	check_player_collisions(t_game *game)
{
	t_node *current_wall_node = game->walls->head;
	t_game_object *current_wall;
	game->player->can_move = get_can_move(1,1,1,1);
	while (current_wall_node)
	{
		current_wall = (t_game_object *) current_wall_node->data;
		check_up(game->player, current_wall);
		check_down(game->player, current_wall);
		check_left(game->player, current_wall);
		check_right(game->player, current_wall);
		current_wall_node = current_wall_node->next;
	}
}

void	check_enemies_collisions(t_game *game)
{
	t_node *current_wall_node = game->walls->head;
	t_game_object *current_wall;

	t_node *current_enemy_node = game->enemies->head;
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
		current_enemy_node = game->enemies->head;
		while(current_enemy_node)
		{
			current_enemy = (t_game_object *) current_enemy_node->data;
			if((current_enemy->position.x == current_wall->position.x) && ((current_enemy->position.y - 32) == current_wall->position.y))
				current_enemy->can_move.up = 0;
			if((current_enemy->position.x == current_wall->position.x) && ((current_enemy->position.y + 32) == current_wall->position.y))
				current_enemy->can_move.down = 0;
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