#ifndef IMAGE_MODEL_H
# define IMAGE_MODEL_H

typedef struct s_image {
    void    *img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian;
    int     width;
    int     height;
}   t_image;


t_image *init_image(void *img, char *addr, int bpp, int line_length, int endian, int width, int height);
void destroy_image(t_image *image, void *mlx);

#endif