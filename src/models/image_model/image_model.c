#include "./image_model.h"
#include "../../utils/utils.h"

t_image *init_image(void *img, char *addr, int bpp, int line_length, int endian, int width, int height)
{
	t_image *new_image = ft_calloc(1, sizeof(t_image));
	if (!new_image)
		return (NULL);
	new_image->addr = addr;
	new_image->bpp = bpp;
	new_image->endian = endian;
	new_image->height = height;
	new_image->width = width;
	new_image->img = img;
	new_image->line_length = line_length;
	
	return (new_image);
}

void destroy_image(t_image *image, void *mlx)
{
	if (!image)
		return;
	if (image->img && mlx)
		//mlx_destroy_image(mlx, image);
	free(image);
}