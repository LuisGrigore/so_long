#include "./events.h"
#include "../models/game_state_model/game_state_model.h"
#include "../utils/utils.h"

t_key_to_funct_mapping *init_key_to_funct_mapping(t_hook_funct funct, int keycode, void *param)
{
	t_key_to_funct_mapping *key_to_funct_mapping = ft_calloc(1, sizeof(t_key_to_funct_mapping));

	key_to_funct_mapping->funct = funct;
	key_to_funct_mapping->keycode = keycode;
	key_to_funct_mapping->param = param;

	return (key_to_funct_mapping);
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

void on_x_press(t_game_state *game_state)
{
	destroy_game_state(game_state);
	exit(0);
}