#include "./screen_controller.h"
#include "../../../minilibx/mlx.h"

int get_pixel_color(t_image *img, int x, int y)
{
    char *pixel;
    if (x < 0 || x >= img->width || y < 0 || y >= img->height)
        return 0;
    pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
    return *(int *)pixel;
}

void    add_image_to_buff(t_screen *screen, t_image *img, t_vector2 position) {
    int i, j;
    int color;
    int pixel_index_grande;
    int pixel_index_pequena;

    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            pixel_index_grande = ((position.y + i) * screen->buffer->line_length) + ((position.x + j) * (screen->buffer->bpp / 8));

            if ((position.y + i) < screen->buffer->height && (position.x + j) < screen->buffer->width) {
                pixel_index_pequena = (i * img->line_length) + (j * (img->bpp / 8));
                color = *(int *)(img->addr + pixel_index_pequena);

                if (color != -16777216) {
                    *(int *)(screen->buffer->addr + pixel_index_grande) = color;
                }
            }
        }
    }
    mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->buffer->img, 0, 0);
}

void draw_screen_buff(t_screen *screen)
{
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->buffer->img, 0, 0);
}