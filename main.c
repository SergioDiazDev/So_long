/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:54:17 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/30 16:24:26 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int main(int argc, char **argv)
{
	mlx_t* mlx;
	mlx_image_t* background;
	mlx_image_t* mina;

	if (argc != 2)
		return (write(1, "\n[ERROR]: Numero de argumentos no valido.\n\n", 43), 0);
	ft_read_map(argv[1]);
	(void) argv;
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

void	ft_read_map(char *name_map)
{
	int	size;
	int	fd;

	size = ft_strlen(name_map);
	if (size)
	{
		if (ft_memcmp(&name_map[size - 4], ".ber", 4))
			exit(write(1, "\n[ERROR]La extencion no es \".ber\".\n\n", 37));
		fd = open(name_map, O_RDONLY);
		printf("%s", get_next_line(fd));
	}
	exit(write(1, "[ERROR]Como has llegado aqui????", 33));
}