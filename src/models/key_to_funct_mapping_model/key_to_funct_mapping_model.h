#ifndef KEY_TO_FUNCT_MAPPING_MODEL_H
# define KEY_TO_FUNCT_MAPPING_MODEL_H
# include "../../utils/t_hook_funct.h"

typedef struct s_key_to_funct_mapping
{
	int				keycode;
	t_hook_funct	funct;
	void			*param;
}	t_key_to_funct_mapping;

t_key_to_funct_mapping *init_key_to_funct_mapping(t_hook_funct funct, int keycode, void *param);

#endif
