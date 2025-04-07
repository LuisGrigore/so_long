#include "./game_object_model.h"
#include "../../utils/utils.h"

t_game_object	*init_game_object(t_image *image, t_vector2 position,
	t_vector2 displacement, e_game_object_type type, t_can_move can_move)
{
	t_game_object *game_object = ft_calloc(1, sizeof(t_game_object));
	game_object->image = image;
	game_object->position = position;
	game_object->displacement = displacement;
	game_object->type = type;
	game_object->can_move = can_move;
	return game_object;
}

t_can_move get_can_move(int	up, int	down, int	left, int	right)
{
	t_can_move can_move;
	can_move.up = up;
	can_move.down = down;
	can_move.left = left;
	can_move.right = right;

	return can_move;
}