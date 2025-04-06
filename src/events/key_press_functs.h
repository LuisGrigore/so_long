#ifndef KEY_PRESS_FUNCTS_H
# define KEY_PRESS_FUNCTS_H
# include "../models/game_state_model/game_state_model.h"

void	on_esc(t_game_state *game_state);
void	on_up_key(void *game_ptr);
void	on_down_key(void *game_ptr);
void	on_left_key(void *game_ptr);
void	on_right_key(void *game_ptr);

#endif
