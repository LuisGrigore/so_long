#ifndef SCREEN_CONTROLLER_H
# define SCREEN_CONTROLLER_H
# include "../../models/screen_model/screen_model.h"
# include "../../models/image_model/image_model.h"

t_image *load_xpm_image(t_screen *screen, char *xpm_path);
void    add_image_to_buff(t_screen *screen, t_image *img, t_vector2 position);
void draw_screen_buff(t_screen *screen);

#endif