/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controller.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:17:14 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/08 02:39:11 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CONTROLLER_H
# define GAME_CONTROLLER_H
# include "../../models/game_model/game_model.h"
# include "../../models/game_object_model/game_object_model.h"
# include "../../image_butch.h"

void	load_game_objects_from_map(t_game *game, t_image_butch image_butch,
			int map_fd, int tile_size);
void	check_player_collisions(t_game *game);
void	check_enemies_collisions(t_game *game);
void	update_game(t_game *game);

#endif
