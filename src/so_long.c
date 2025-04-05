#include "../minilibx/mlx.h"
#include "./models/image_model/image_model.h"
#include "./models/screen_model/screen_model.h"
#include "./models/game_object_model/game_object_model.h"
#include "./controllers/screen_controller/screen-controller.h"
#include "./config/screen_config.h"
#include <stdio.h>


int main() {
	t_screen *screen = init_screen(get_vector_from_floats(WINDOW_X_SIZE, WINDOW_Y_SIZE), WINDOW_TITLE);

    t_image img_pequena;


	img_pequena = *load_xpm_image(screen, "./sprites/player.xpm");

    add_image_to_buff(screen, &img_pequena, get_vector_from_floats(100, 150));
    add_image_to_buff(screen, &img_pequena, get_vector_from_floats(110, 150));
    add_image_to_buff(screen, &img_pequena, get_vector_from_floats(200, 150));

	draw_screen_buff(screen);

    mlx_loop(screen->mlx);
    
    return 0;
}
