#include "./game_object_model.h"
#include "../../utils/utils.h"

t_game_object	*init_game_object(t_list *images, t_vector2 position, t_vector2 displacement, e_game_object_type type, t_can_move can_move)
{
	t_game_object *game_object = ft_calloc(1, sizeof(t_game_object));
	game_object->images = images;
	game_object->position = position;
	game_object->displacement = displacement;
	game_object->type = type;
	game_object->can_move = can_move;
	game_object->current_image = (t_image *) images->head->data;
	return game_object;
}

