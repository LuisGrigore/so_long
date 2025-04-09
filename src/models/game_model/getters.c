#include "./game_model.h"

t_game_object *get_player(t_game *game)
{
	return (game->player);
}

t_game_object *get_exit(t_game *game)
{
	return (game->exit);
}

t_list *get_walls(t_game *game)
{
	return (game->walls);
}

t_list *get_floors(t_game *game)
{
	return (game->floors);
}

t_list *get_enemies(t_game *game)
{
	return (game->enemies);
}