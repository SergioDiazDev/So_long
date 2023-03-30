// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MLX42/include/MLX42/MLX42.h"

#define WIDTH 1024
#define HEIGHT 1024
#define SIZE_BLOCK 64

static mlx_image_t* image;

void ft_hook(mlx_key_data_t keydata, void *param)
	{
		mlx_t* mlx = param;

		if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
			mlx_close_window(mlx);
		if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
			image->instances[0].y -= SIZE_BLOCK;
		if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
			image->instances[0].y += SIZE_BLOCK;
		if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
			image->instances[0].x -= SIZE_BLOCK;
		if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
			image->instances[0].x += SIZE_BLOCK;
	}

int main()
{
	mlx_t* mlx;
	mlx_image_t* background;
	mlx_image_t* mina;
	

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "so_long", false)))
		return(puts(mlx_strerror(mlx_errno)), EXIT_FAILURE);
	background = mlx_texture_to_image(mlx, mlx_load_png("assets/background.png"));
	mina = mlx_texture_to_image(mlx, mlx_load_png("assets/mina.png"));
	image = mlx_texture_to_image(mlx, mlx_load_png("assets/prota.png"));
	mlx_image_to_window(mlx, background, 0, 0);
	mlx_image_to_window(mlx, background, 64, 0);
	mlx_image_to_window(mlx, background, 0, 64);
	mlx_image_to_window(mlx, background, 64, 64);
	mlx_image_to_window(mlx, mina, 0, 0);
	mlx_image_to_window(mlx, image, 0, 0);

	mlx_key_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
