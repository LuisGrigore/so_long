#ifndef IMAGE_BUTCH_H
# define IMAGE_BUTCH_H

#include "./models/image_model/image_model.h"

typedef struct s_image_butch
{
	t_image *player_image;
	t_image *wall_image;
	t_image *floor_image;
	t_image *exit_image;
	t_image *coin_image;
	t_image *enemy_image;
} t_image_butch;

#endif