#ifndef EVENTS_H
# define EVENTS_H
# include "../utils/list.h"
# include "../utils/t_hook_funct.h"
# include "../models/game_state_model/game_state_model.h"

typedef struct s_key_to_funct_mapping
{
	int				keycode;
	t_hook_funct	funct;
	void			*param;
}	t_key_to_funct_mapping;

t_key_to_funct_mapping *init_key_to_funct_mapping(t_hook_funct funct, int keycode, void *param);

int	on_key_press(int keycode, t_list *keycode_functs);
void on_x_press(t_game_state *game_state);

#endif