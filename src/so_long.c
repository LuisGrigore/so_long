#include "../minilibx/mlx.h"
#include "./models/image_model/image_model.h"
#include "./models/game_object_model/game_object_model.h"
#include "./controllers/screen_controller/screen_controller.h"
#include "./controllers/game_controller/game_controller.h"

#include "./config/screen_config.h"
#include <stdio.h>


t_game *create_game(t_screen *screen)
{
	t_game *game = init_game();

	t_image *player_image = load_xpm_image(screen, "./sprites/player.xpm");

	load_player_from_file(game, "./maps/test", player_image);

	return game;
}

int main() {
	t_screen *screen = init_screen(get_vector_from_floats(WINDOW_X_SIZE, WINDOW_Y_SIZE), WINDOW_TITLE);

    t_game *game = create_game(screen);

    add_image_to_buff(screen, game->player->image, game->player->position);
    

	draw_screen_buff(screen);

    mlx_loop(screen->mlx);
    
    return 0;
}
