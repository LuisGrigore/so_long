#include "./game_object_model.h"
#include <math.h>

void	move_y(t_game_object *game_object, int offset)
{
	game_object->position.y += offset;
}

void	move_x(t_game_object *game_object, int offset)
{
	game_object->position.x += offset;
}

void	offset_game_object_position(t_game_object *game_object, t_vector2 offset)
{
	move_x(game_object, offset.x);
	move_y(game_object, offset.y);
}