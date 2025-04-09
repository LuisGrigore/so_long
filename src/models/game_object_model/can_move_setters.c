#include "./game_object_model.h"
#include "../../utils/utils.h"

void	set_can_move_up(t_game_object *game_object, t_bool can_move)
{
	game_object->can_move.up = can_move;
}

void	set_can_move_down(t_game_object *game_object, t_bool can_move)
{
	game_object->can_move.down = can_move;

}

void	set_can_move_left(t_game_object *game_object, t_bool can_move)
{
	game_object->can_move.left = can_move;

}

void	set_can_move_right(t_game_object *game_object, t_bool can_move)
{
	game_object->can_move.right = can_move;

}