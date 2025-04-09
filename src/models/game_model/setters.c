#include "./game_model.h"

void set_player(t_game *game, t_game_object *player)
{
	game->player = player;
}

void set_exit(t_game *game, t_game_object *exit)
{
	game->exit = exit;
}

void add_wall(t_game *game, t_game_object *wall)
{
	insert_front(game->walls, wall);
}

void add_floor(t_game *game, t_game_object *floor)
{
	insert_front(game->floors, floor);
}

void add_enemy(t_game *game, t_game_object *enemy)
{
	insert_front(game->enemies, enemy);
}