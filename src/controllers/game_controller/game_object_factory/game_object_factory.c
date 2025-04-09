#include "./game_object_factory.h"
#include "../../../utils/vector2.h"
#include "../../../utils/list.h"

void	insert_player(t_game *game, t_vector2 position, t_image_butch image_butch)
{
	t_list *images;
	t_game_object *new_player;

	images = init_list(sizeof(t_image));
	insert_front(images, image_butch.player_image);
	new_player = init_game_object(images, position, get_vector(0, 0), PLAYER, get_can_move(1,1,1,1));
	set_player(game, new_player);
}

void	insert_floor(t_game *game, t_vector2 position, t_image_butch image_butch)
{
	t_list *images;
	t_game_object *new_floor;

	images = init_list(sizeof(t_image));
	insert_front(images, image_butch.floor_image);
	new_floor = init_game_object(images, position, get_vector(0, 0), MAP, get_can_move(0,0,0,0));
	add_floor(game, new_floor);
}

void	insert_wall(t_game *game, t_vector2 position, t_image_butch image_butch)
{
	t_list *images;
	t_game_object *new_wall;

	images = init_list(sizeof(t_image));
	insert_front(images, image_butch.wall_image);
	new_wall = init_game_object(images, position, get_vector(0, 0), MAP, get_can_move(0,0,0,0));
	add_wall(game, new_wall);
}

void	insert_enemy(t_game *game, t_vector2 position, t_image_butch image_butch)
{
	t_list *images;
	t_game_object *new_enemy;

	images = init_list(sizeof(t_image));
	//cambiar imagen por enemy_image cuando se tenga
	insert_front(images, image_butch.wall_image);
	new_enemy = init_game_object(images, position, get_vector(0, 0), ENEMY, get_can_move(0,0,0,0));
	add_enemy(game, new_enemy);
}

void	game_object_factory(t_game *game, t_image_butch image_butch, t_vector2 position, char c)
{	
	if (c == 'P')
	{
		insert_player(game, position, image_butch);
		insert_floor(game, position, image_butch);
	}
	else if (c == '1')
	{
		insert_wall(game, position, image_butch);
	}
	else if (c == '0')
	{
		insert_floor(game, position, image_butch);
	}
	else if (c == 'e')
	{
		insert_enemy(game, position, image_butch);
		insert_floor(game, position, image_butch);
	}
}