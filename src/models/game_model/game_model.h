/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_model.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:27:46 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/09 12:23:31 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_MODEL_H
# define GAME_MODEL_H
# include "../../utils/list.h"
# include "../game_object_model/game_object_model.h"

typedef void	(*t_update_funct)(double);

typedef struct s_game_model_metadata
{
	double	delta_time;
	double	acumulator;
	double	slice;	
}	t_game_metadata;

typedef struct s_game_model
{
	//t_game_metadata	*data;
	t_list			*walls;
	t_list			*floors;
	t_list			*coins;
	t_list			*enemies;
	t_game_object	*player;
	t_game_object	*exit;
}	t_game;

t_game	*init_game(void);
void	destroy_game(t_game *game);

t_game_object *get_player(t_game *game);
t_game_object *get_exit(t_game *game);
t_list *get_walls(t_game *game);
t_list *get_floors(t_game *game);
t_list *get_enemies(t_game *game);

void set_player(t_game *game, t_game_object *player);
void set_exit(t_game *game, t_game_object *exit);
void add_wall(t_game *game, t_game_object *wall);
void add_floor(t_game *game, t_game_object *floor);
void add_enemy(t_game *game, t_game_object *enemy);

#endif