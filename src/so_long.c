#include "./models/image_model/image_model.h"
#include "./controllers/game_state_controller/game_state_controller.h"
#include "./models/game_object_model/game_object_model.h"
#include "./controllers/screen_controller/screen_controller.h"
#include "./controllers/game_controller/game_controller.h"
#include "./image_butch.h"
#include "./config/screen_config.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

t_image_butch load_images(t_screen *screen, char *images_path)
{
	t_image_butch image_butch;
	image_butch.player_image = load_image(screen, "./sprites/player.xpm");
	image_butch.wall_image = load_image(screen, "./sprites/wall.xpm");
	image_butch.floor_image = load_image(screen, "./sprites/floor.xpm");
	return (image_butch);
}

t_game *load_game(t_screen *screen, char *map_path, t_image_butch image_butch)
{
	t_game *game = init_game();

	int map_fd = open(map_path, O_RDONLY);

	load_game_objects_from_map(game, image_butch, map_fd, TILE_SIZE);

	return game;
}

int main() {
	t_screen *screen = init_screen(get_vector_from_floats(WINDOW_X_SIZE, WINDOW_Y_SIZE), WINDOW_TITLE);

	t_image_butch image_butch = load_images(screen, "");

    t_game *game = load_game(screen, "./maps/test", image_butch);

	t_game_state *game_state = init_game_state(game, screen);

	set_loop_hook(screen, game_loop, game_state);

	start_loop(screen);
    
    return 0;
}
