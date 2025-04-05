#include "./game_controller.h"
#include <fcntl.h>  // Para O_RDONLY
#include <unistd.h> // Para open, read, close
#include <stdio.h>
#include <errno.h>

void load_player_from_file(t_game *game, char *path, t_image *image, int tile_size)
{
    int fd = open(path, O_RDONLY);
	char c;
	int read_ret = 0;

	t_vector2 current_pos = get_vector_from_floats(0,0);

    if (fd == -1) {
        perror("Error al abrir el archivo");
        return;
    }

	read_ret = read(fd, &c, 1);
	while(read_ret == 1)
	{
		
		if(c == 'P')
		{
			game->player = init_game_object(image, current_pos, PLAYER);
		}
		current_pos.x += tile_size;
		if(c == '\n')
		{
			current_pos.y += tile_size;
			current_pos.x = 0;
		}
		read_ret = read(fd, &c, 1);
	}
	close(fd);
}