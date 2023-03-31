/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:54:17 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/31 10:52:47 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WIDTH 1024
#define HEIGHT 1024
#define SIZE_BLOCK 64

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_so_long	*game;

	game = (t_so_long *) param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		game->player->instances[0].y -= SIZE_BLOCK;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		game->player->instances[0].y += SIZE_BLOCK;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		game->player->instances[0].x -= SIZE_BLOCK;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		game->player->instances[0].x += SIZE_BLOCK;
}

int	main(int argc, char **argv)
{
	t_so_long	game;

	if (argc != 2)
		return (write(1, "\n[ERROR]: Numero de argumentos no valido.\n\n", 43), 0);
	ft_read_map(&game, argv[1]);
	(void) argv;
	if (!(game.mlx = mlx_init(WIDTH, HEIGHT, "so_long", false)))
		return (puts(mlx_strerror(mlx_errno)), EXIT_FAILURE);
	game.bg = mlx_texture_to_image(game.mlx, mlx_load_png("img/bg.png"));
	game.mine = mlx_texture_to_image(game.mlx, mlx_load_png("img/mine.png"));
	game.player = mlx_texture_to_image(game.mlx, mlx_load_png("img/main.png"));
	mlx_image_to_window(game.mlx, game.bg, 0, 0);
	mlx_image_to_window(game.mlx, game.bg, 64, 0);
	mlx_image_to_window(game.mlx, game.bg, 0, 64);
	mlx_image_to_window(game.mlx, game.bg, 64, 64);
	mlx_image_to_window(game.mlx, game.mine, 0, 0);
	mlx_image_to_window(game.mlx, game.player, 0, 0);
	mlx_key_hook(game.mlx, ft_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}

void	ft_read_map(t_so_long *game, char *name_map)
{
	int		size;
	char	*temp;
	int		fd;

	size = ft_strlen(name_map);
	if (size)
	{
		if (ft_memcmp(&name_map[size - 4], ".ber", 4))
			exit(write(1, "\n[ERROR]La extencion no es \".ber\".\n\n", 37));
		fd = open(name_map, O_RDONLY);
		size = 0;
		temp = get_next_line(fd);
		while (temp)
		{
			size++;
			free(temp);
			temp = get_next_line(fd);
		}
		close(fd);
		game->map = ft_calloc(sizeof(char *), size);
		fd = open(name_map, O_RDONLY);
		while (size--)
			game->map[size] = get_next_line(fd);
		close(fd);
	}
	//exit(write(1, "[ERROR]Como has llegado aqui????", 33));
}
