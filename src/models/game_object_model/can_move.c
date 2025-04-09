#include "./game_object_model.h"

t_can_move get_can_move(t_bool	up, t_bool	down, t_bool left, t_bool right)
{
	t_can_move can_move;
	can_move.up = up;
	can_move.down = down;
	can_move.left = left;
	can_move.right = right;

	return can_move;
}

void	restrict_all_movement(t_game_object *game_object)
{
	set_can_move_up(game_object, FALSE);
	set_can_move_down(game_object, FALSE);
	set_can_move_left(game_object, FALSE);
	set_can_move_right(game_object, FALSE);
}

void	allow_all_movement(t_game_object *game_object)
{
	set_can_move_up(game_object, TRUE);
	set_can_move_down(game_object, TRUE);
	set_can_move_left(game_object, TRUE);
	set_can_move_right(game_object, TRUE);
}