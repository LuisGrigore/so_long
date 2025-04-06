#include "./key_to_funct_mapping_model.h"
#include "../../utils/utils.h"

t_key_to_funct_mapping *init_key_to_funct_mapping(t_hook_funct funct, int keycode, void *param)
{
	t_key_to_funct_mapping *key_to_funct_mapping = ft_calloc(1, sizeof(t_key_to_funct_mapping));

	key_to_funct_mapping->funct = funct;
	key_to_funct_mapping->keycode = keycode;
	key_to_funct_mapping->param = param;

	return(key_to_funct_mapping);
}