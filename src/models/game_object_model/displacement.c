#include "./game_object_model.h"
#include <math.h>

void	displace_x(t_game_object *game_object, unsigned int offset)
{
	if(game_object->displacement.x > 0)
	{
		game_object->position.x ++;
		game_object->displacement.x --;
	}
	if(game_object->displacement.x < 0)
	{
		game_object->position.x --;
		game_object->displacement.x ++;
	}
}

void	displace_y(t_game_object *game_object, unsigned int offset)
{
	if(game_object->displacement.y > 0)
	{
		game_object->position.y ++;
		game_object->displacement.y --;
	}
	if(game_object->displacement.y < 0)
	{
		game_object->position.y --;
		game_object->displacement.y ++;
	}
}

void	displace(t_game_object *game_object, unsigned int offset)
{
	displace_x(game_object, offset);
	displace_y(game_object, offset);
}