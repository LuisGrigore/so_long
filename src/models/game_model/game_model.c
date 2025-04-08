/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_model.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:26:22 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/08 02:19:51 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./game_model.h"
#include "../../utils/utils.h"

t_game	*init_game(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	game->coins = init_list(sizeof(t_game_object));
	game->exit = init_list(sizeof(t_game_object));
	game->floors = init_list(sizeof(t_game_object));
	game->player = init_list(sizeof(t_game_object));
	game->walls = init_list(sizeof(t_game_object));
	game->enemies = init_list(sizeof(t_game_object));
	return (game);
}

void	destroy_game(t_game *game)
{
	free(game);
}
