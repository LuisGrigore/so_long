#include "./models/image_model/image_model.h"
#include "./controllers/game_state_controller/game_state_controller.h"
#include "./models/game_object_model/game_object_model.h"
#include "./models/key_to_funct_mapping_model/key_to_funct_mapping_model.h"
#include "./controllers/screen_controller/screen_controller.h"
#include "./controllers/game_controller/game_controller.h"
#include "./controllers/player_controller/player_controller.h"
#include "./image_butch.h"
#include "./config/screen_config.h"
#include "./config/key_code_conf.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
# include "./utils/t_hook_funct.h"

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

void on_x(t_game_state *game_state)
{
	destroy_game_state(game_state);
	exit(0);
}

void on_esc(t_game_state *game_state)
{
	destroy_game_state(game_state);
	exit(0);
}



int	on_key_press(int keycode, t_list *keycode_functs)
{
	t_node *current_node = keycode_functs->head;
	t_key_to_funct_mapping *current_key_to_funct_mapping;

	while (current_node)
	{
		current_key_to_funct_mapping = (t_key_to_funct_mapping *)current_node->data;
		if (current_key_to_funct_mapping->keycode == keycode)
		{
			current_key_to_funct_mapping->funct(current_key_to_funct_mapping->param);
			return (0);
		}
		current_node = current_node->next;
	}
	return (0);
}
void	on_up_key(void *game_ptr)
{
	t_game *game = (t_game *) game_ptr;
	move_player(game->player, get_vector_from_floats(0, -32));
}

void	on_down_key(void *game_ptr)
{
	t_game *game = (t_game *) game_ptr;
	move_player(game->player, get_vector_from_floats(0, 32));
}

void	on_right_key(void *game_ptr)
{
	t_game *game = (t_game *) game_ptr;
	move_player(game->player, get_vector_from_floats(32, 0));
}

void	on_left_key(void *game_ptr)
{
	t_game *game = (t_game *) game_ptr;
	move_player(game->player, get_vector_from_floats(-32, 0));
}


t_list *get_key_funct_mappings(t_game_state *game_state)
{
	t_list *key_funct_mappings = init_list(sizeof(t_key_to_funct_mapping));

	insert_front(key_funct_mappings, init_key_to_funct_mapping(on_up_key, MOVE_UP_KEY_CODE, game_state->game));
	insert_front(key_funct_mappings, init_key_to_funct_mapping(on_down_key, MOVE_DOWN_KEY_CODE, game_state->game));
	insert_front(key_funct_mappings, init_key_to_funct_mapping(on_right_key, MOVE_RIGHT_KEY_CODE, game_state->game));
	insert_front(key_funct_mappings, init_key_to_funct_mapping(on_left_key, MOVE_LEFT_KEY_CODE, game_state->game));
	insert_front(key_funct_mappings, init_key_to_funct_mapping(on_esc, ESC, game_state->game));

	return (key_funct_mappings);
}


int main() {
	t_screen *screen = init_screen(get_vector_from_floats(WINDOW_X_SIZE, WINDOW_Y_SIZE), WINDOW_TITLE);

	t_image_butch image_butch = load_images(screen, "");

    t_game *game = load_game(screen, "./maps/test", image_butch);

	t_game_state *game_state = init_game_state(game, screen);

	set_loop_hook(screen, game_loop, game_state);

	set_x_hook(screen, on_x, game_state);

	set_key_hook(screen, on_key_press, get_key_funct_mappings(game_state));

	start_loop(screen);
    
    return 0;
}
