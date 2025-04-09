#include "./key_press_functs.h"
#include <stdlib.h>

void on_esc(t_game_state *game_state)
{
	destroy_game_state(game_state);
	exit(0);
}

void	on_up_key(void *game_ptr)
{
	t_game *game = (t_game *) game_ptr;
	move_player(game->player, get_vector(0, -32));
}

void	on_down_key(void *game_ptr)
{
	t_game *game = (t_game *) game_ptr;
	move_player(game->player, get_vector(0, 32));
}

void	on_right_key(void *game_ptr)
{
	t_game *game = (t_game *) game_ptr;
	move_player(game->player, get_vector(32, 0));
}

void	on_left_key(void *game_ptr)
{
	t_game *game = (t_game *) game_ptr;
	move_player(game->player, get_vector(-32, 0));
}