#include "./screen_controller.h"
#include "../../../minilibx/mlx.h"

void set_loop_hook(t_screen *screen, t_hook_funct loop_funct, void *param)
{
	mlx_loop_hook(screen->mlx, loop_funct, param);
}

void start_loop(t_screen *screen)
{
	mlx_loop(screen->mlx);
}