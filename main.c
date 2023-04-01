/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:54:17 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/01 13:37:13 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_so_long	*game;

	game = (t_so_long *) param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_exit_free(FIN_DE_PROGRAMA, game);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		game->player->instances[0].y -= SIZE;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		game->player->instances[0].y += SIZE;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		game->player->instances[0].x -= SIZE;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		game->player->instances[0].x += SIZE;
}

int	main(int argc, char **argv)
{
	t_so_long	game;

	atexit(ft_leaks);
	if (argc != 2)
		return (write(1, "\n[ERROR]: Numero de argumentos no valido.\n\n", 43), 0);
	game.height = 0;
	game.width = 0;
	ft_read_map(&game, argv[1]);
	ft_init_so_long(&game);
	ft_pain_map(&game);
	mlx_key_hook(game.mlx, ft_hook, &game);
	mlx_loop(game.mlx);
	ft_exit_free(FIN_DE_PROGRAMA, &game);
	return (EXIT_SUCCESS);
}

void	ft_read_map(t_so_long *g, char *name_map)
{
	int		size;
	int		fd;

	size = ft_strlen(name_map);
	if (size)
	{
		if (ft_memcmp(&name_map[size - 4], ".ber", 4))
			ft_exit_free(EXTENSION_NO_BER, g);
		fd = open(name_map, O_RDONLY);
		g->temp = get_next_line(fd);
		size = ft_strlen(g->temp) - 1;
		g->width = size;
		while (g->temp)
		{
			free(g->temp);
			g->temp = get_next_line(fd);
			if (ft_strlen(g->temp) - 1 != g->width && g->temp)
				ft_exit_free(MAPA_NO_CORRECTO, g);
			g->height++;
		}
		if (g->height == g->width || g->height <= 2 || g->width <= 2)
			ft_exit_free(MAPA_NO_CORRECTO, g);
		free(g->temp);
		close(fd);
		g->map = ft_calloc(sizeof(char *), g->height + 1);
		fd = open(name_map, O_RDONLY);
		size = 0;
		close(fd);
	}
}

void	ft_exit_free(int nb_error, t_so_long *game)
{
	if (nb_error == EXTENSION_NO_BER)
		exit(write(1, "\n[ERROR]La extencion no es \".ber\".\n\n", 37));
	if (nb_error == FIN_DE_PROGRAMA)
	{
		while (--game->height)
			free(game->map[game->height]);
		mlx_delete_texture(game->t_bg);
		mlx_delete_texture(game->t_mine);
		mlx_delete_texture(game->t_player);
		mlx_delete_texture(game->t_coral);
		mlx_delete_texture(game->t_egg);
		mlx_delete_texture(game->t_rocket);
		mlx_delete_texture(game->t_sushi);
		mlx_delete_image(game->mlx, game->bg);
		mlx_delete_image(game->mlx, game->mine);
		mlx_delete_image(game->mlx, game->player);
		mlx_delete_image(game->mlx, game->coral);
		mlx_delete_image(game->mlx, game->egg);
		mlx_delete_image(game->mlx, game->rocket);
		mlx_delete_image(game->mlx, game->sushi);
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		exit(write(1, "\n[FIN_DE_PROGRAMA]\n\n", 21));
	}
	if (nb_error == MAPA_NO_CORRECTO)
	{
		printf("\nH:%d\nW:%d\nT:%d\n", game->height, game->width, ft_strlen(game->temp));
		exit(write(1, "\n[ERROR]Mapa no correcto.\n\n", 28));
	}
}

void	ft_leaks(void)
{
	system("leaks so_long");
}
