/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:54:17 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/31 13:21:14 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define SIZE_BLOCK 64

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_so_long	*game;

	game = (t_so_long *) param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_exit_free(1, game);
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

	atexit(ft_leaks);
	if (argc != 2)
		return (write(1, "\n[ERROR]: Numero de argumentos no valido.\n\n", 43), 0);
	ft_read_map(&game, argv[1]);
	ft_init_so_long(&game);
	mlx_image_to_window(game.mlx, game.bg, 0, 0);
	mlx_image_to_window(game.mlx, game.mine, 0, 0);
	mlx_image_to_window(game.mlx, game.player, 0, 0);
	mlx_key_hook(game.mlx, ft_hook, &game);
	mlx_loop(game.mlx);
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
			ft_exit_free(-1, game);
		fd = open(name_map, O_RDONLY);
		size = 0;
		temp = get_next_line(fd);
		while (temp)
		{
			size++;
			free(temp);
			temp = get_next_line(fd);
		}
		free(temp);
		close(fd);
		game->map = ft_calloc(sizeof(char *), size);
		free(game->map);
		fd = open(name_map, O_RDONLY);
		while (size--)
			game->map[size] = get_next_line(fd);
		close(fd);
	}
}

void	ft_exit_free(int nb_error, t_so_long *game)
{
	if (nb_error == -1)
		exit(write(1, "\n[ERROR]La extencion no es \".ber\".\n\n", 37));
	if (nb_error == 1)
	{
		mlx_delete_texture(game->t_bg);
		mlx_delete_texture(game->t_mine);
		mlx_delete_texture(game->t_player);
		mlx_delete_image(game->mlx, game->bg);
		mlx_delete_image(game->mlx, game->mine);
		mlx_delete_image(game->mlx, game->player);
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		exit(write(1, "\n[ERROR]Durante la ejecucion\n\n", 31));
	}
}

void	ft_leaks(void)
{
	system("leaks so_long");
}
