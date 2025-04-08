/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_model.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:27:46 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/08 02:19:37 by lgrigore         ###   ########.fr       */
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

#endif