/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:54:17 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/01 15:12:46 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_so_long	*g;

	g = (t_so_long *) param;
	ft_where_is(g);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_exit_free(FIN_DE_PROGRAMA, g);
	if (g->pos[1] > 0)
	{
		if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		{
			g->player->instances[0].y -= SIZE;
			g->pos[1]--;
			g->count++;
		}
	}
	if (g->pos[1] < g->height - 1)
	{
		if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		{
			g->player->instances[0].y += SIZE;
			g->pos[1]++;
			g->count++;
		}
	}
	if (g->pos[0] > 0)
	{	
		if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		{
			g->player->instances[0].x -= SIZE;
			g->pos[0]--;
			g->count++;
		}
	}
	if (g->pos[0] < g->width - 1)
	{
		if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		{
			g->player->instances[0].x += SIZE;
			g->pos[0]++;
			g->count++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_so_long	game;

	atexit(ft_leaks);
	if (argc != 2)
		return (write(1, "\n[ERROR]: Numero de argumentos no valido.\n\n", 43), 0);
	game.height = 0;
	game.width = 0;
	game.count = 0;
	ft_read_map(&game, argv[1]);
	ft_init_so_long(&game);
	ft_pain_map(&game);
	mlx_key_hook(game.mlx, ft_hook, &game);
	mlx_loop(game.mlx);
	ft_exit_free(FIN_DE_PROGRAMA, &game);
	return (EXIT_SUCCESS);
}

void	ft_where_is(t_so_long *g)
{
	if (g->map[g->pos[1]][g->pos[0]] == 'X')
		ft_exit_free(FIN_DE_PROGRAMA, g);
	if (g->map[g->pos[1]][g->pos[0]] == 'C')
	{
		g->sushi->instances->enabled = 0;
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
		ft_clean_image(game);
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

void	ft_clean_image(t_so_long *game)
{
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
}

void	ft_leaks(void)
{
	system("leaks so_long");
}
