/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:14:12 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/06 17:17:04 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./game_controller.h"
#include <stdio.h>
#include <errno.h>

void	game_object_factory(t_game *game, t_image_butch image_butch,
		t_vector2 position, char c)
{
	if (c == 'P')
	{
		game->player = init_game_object(image_butch.player_image,
				position, PLAYER);
		insert_front(game->floors, init_game_object(image_butch.floor_image,
				position, MAP));
	}
	else if (c == '1')
		insert_front(game->walls, init_game_object(image_butch.wall_image,
				position, MAP));
	else if (c == '0')
		insert_front(game->floors, init_game_object(image_butch.floor_image,
				position, MAP));
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
