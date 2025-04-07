/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state_controller.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:10:50 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/08 01:46:33 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_STATE_CONTROLLER_H
# define GAME_STATE_CONTROLLER_H
# include "../../models/game_state_model/game_state_model.h"

# ifndef STEP
#  define STEP 5
# endif

int	game_loop(t_game_state *game_state);

#endif
