#include "./game_object_model.h"
#include "../../utils/utils.h"

t_game_object *init_game_object(t_image *image, t_vector2 position, e_game_object_type type)
{
	t_game_object *game_object = ft_calloc(1, sizeof(t_game_object));
	game_object->image = image;
	game_object->position = position;
	game_object->type = type;
	return game_object;
}