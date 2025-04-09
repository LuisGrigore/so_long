#include "./game_object_model.h"

t_bool can_move_up(t_game_object *game_object)
{
	return (game_object->can_move.up);
}

t_bool can_move_down(t_game_object *game_object)
{
	return (game_object->can_move.down);
}

t_bool can_move_left(t_game_object *game_object)
{
	return (game_object->can_move.left);
}

t_bool can_move_right(t_game_object *game_object)
{
	return (game_object->can_move.right);
}