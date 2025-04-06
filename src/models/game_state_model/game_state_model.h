#ifndef GAME_STATE_MODEL_H
# define GAME_STATE_MODEL_H
# include "../game_model/game_model.h"
# include "../screen_model/screen_model.h"

typedef struct s_game_state
{
	t_game		*game;
	t_screen	*screen;
} t_game_state;

t_game_state *init_game_state(t_game *game, t_screen *screen);
void destroy_game_state(t_game_state *game_state);

#endif