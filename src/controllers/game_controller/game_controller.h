#ifndef GAME_CONTROLLER_H
# define GAME_CONTROLLER_H
# include "../../models/game_model/game_model.h"
# include "../../models/game_object_model/game_object_model.h"
# include "../../image_butch.h"

void load_game_objects_from_map(t_game *game, t_image_butch image_butch, int map_fd, int tile_size);

#endif