#include "./game_model.h"
#include "../../utils/utils.h"

t_game *init_game()
{
	t_game *game = ft_calloc(1, sizeof(t_game));
	game->coins  = init_list(sizeof(t_game_object));
	game->exit = init_list(sizeof(t_game_object));;
	game->floors = init_list(sizeof(t_game_object));;
	game->player = init_list(sizeof(t_game_object));;
	game->walls = init_list(sizeof(t_game_object));;
	return (game);
}

void destroy_game(t_game *game)
{
	free(game);
}