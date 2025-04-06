#include "./game_state_model.h"
#include "../../utils/utils.h"


t_game_state *init_game_state(t_game *game, t_screen *screen)
{
	t_game_state *new_game_state;

	new_game_state = ft_calloc(1, sizeof(t_game_state));
	if (!new_game_state)
		return (NULL);
	new_game_state->game = game;
	new_game_state->screen = screen;
	return (new_game_state);
}

void destroy_game_state(t_game_state *game_state)
{
	if (!game_state)
		return;
	if (game_state->game)
		destroy_game(game_state->game);
	if (game_state->screen)
		destroy_screen(game_state->screen);
	free(game_state);
}