#include "./game_controller.h"
#include <fcntl.h>  // Para O_RDONLY
#include <unistd.h> // Para open, read, close
#include <stdio.h>
#include <errno.h>

void load_player_from_file(t_game *game, char *path, t_image *image)
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
		current_pos.x ++;
		if(c == '\n')
		{
			current_pos.y ++;
			current_pos.x = 0;
		}
		if(c == 'P')
		{
			game->player = init_game_object(image, current_pos, PLAYER);
		}
		read_ret = read(fd, &c, 1);
	}
	close(fd);
}