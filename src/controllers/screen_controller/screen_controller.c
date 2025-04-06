#include "./screen_controller.h"
#include <stdlib.h>
#include "../../../minilibx/mlx.h"

t_image *load_image(t_screen *screen, char *xpm_path) {
    void *img;
    char *addr;
    int bpp, line_length, endian;
    int width, height;

    img = mlx_xpm_file_to_image(screen->mlx, xpm_path, &width, &height);
    if (!img) {
        return NULL;
    }

    addr = mlx_get_data_addr(img, &bpp, &line_length, &endian);
    if (!addr) {
        mlx_destroy_image(screen->mlx, img);
        return NULL;
    }

    return init_image(img, addr, bpp, line_length, endian, width, height);
}
