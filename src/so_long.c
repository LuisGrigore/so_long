#include "../minilibx/mlx.h"
#include "./models/image_model/image_model.h"
#include "./models/game_state_model/game_state_model.h"
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
	image_butch.player_image = load_xpm_image(screen, "./sprites/player.xpm");
	image_butch.wall_image = load_xpm_image(screen, "./sprites/wall.xpm");
	image_butch.floor_image = load_xpm_image(screen, "./sprites/floor.xpm");
	return (image_butch);
}

t_game *load_game(t_screen *screen, char *map_path, t_image_butch image_butch)
{
	t_game *game = init_game();

	int map_fd = open(map_path, O_RDONLY);

	load_game_objects_from_map(game, image_butch, map_fd, TILE_SIZE);

	return game;
}

void add_player_to_screen_buff(t_game *game, t_screen *screen)
{
	add_image_to_buff(screen, game->player->image, game->player->position);
}

void add_walls_to_screen_buff(t_game *game, t_screen *screen)
{
	t_node *current_node = game->walls->head;
	t_game_object *current_wall;
	while(current_node)
	{
		current_wall = (t_game_object *) current_node->data;
		add_image_to_buff(screen, current_wall->image, current_wall->position);
		current_node = current_node->next;
	}
}
void add_floors_to_screen_buff(t_game *game, t_screen *screen)
{
	t_node *current_node = game->floors->head;
	t_game_object *current_floor;
	while(current_node)
	{
		current_floor = (t_game_object *) current_node->data;
		add_image_to_buff(screen, current_floor->image, current_floor->position);
		current_node = current_node->next;
	}
}

int game_loop(t_game_state *game_state)
{
	add_floors_to_screen_buff(game_state->game, game_state->screen);
	add_walls_to_screen_buff(game_state->game, game_state->screen);
    add_player_to_screen_buff(game_state->game, game_state->screen);
	draw_screen_buff(game_state->screen);
}

int main() {
	t_screen *screen = init_screen(get_vector_from_floats(WINDOW_X_SIZE, WINDOW_Y_SIZE), WINDOW_TITLE);

	t_image_butch image_butch = load_images(screen, "");

    t_game *game = load_game(screen, "./maps/test", image_butch);

	t_game_state *game_state = init_game_state(game, screen);

	mlx_loop_hook(screen->mlx, game_loop, (void *) game_state);

    mlx_loop(screen->mlx);
    
    return 0;
}
