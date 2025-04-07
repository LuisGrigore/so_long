/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state_model.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:30:28 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/08 01:14:03 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_STATE_MODEL_H
# define GAME_STATE_MODEL_H
# include "../game_model/game_model.h"
# include "../screen_model/screen_model.h"

typedef struct s_game_state
{
	t_game		*game;
	t_screen	*screen;
	int			step_counter;
}	t_game_state;

t_game_state	*init_game_state(t_game *game, t_screen *screen, int step_counter);
void			destroy_game_state(t_game_state *game_state);

#endif
