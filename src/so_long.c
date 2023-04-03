/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:54:17 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/03 17:48:14 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_so_long	g;

	atexit(ft_leaks);
	if (argc != 2)
		return (write(1, "\n[ERROR]: Numero de argumentos no valido.\n\n", 43), 0);
	g.h = 0;
	g.w = 0;
	g.steps = 0;
	ft_read_map(&g, argv[1]);
	ft_correct_map(&g);
	ft_init_so_long(&g);
	ft_pain_map(&g);
	mlx_image_to_window(g.mlx, g.player, g.pos[0] * S, g.pos[1] * S);
	g.map[g.pos[0]][g.pos[1]] = 0;
	mlx_key_hook(g.mlx, ft_hook, &g);
	mlx_loop(g.mlx);
	ft_exit_free(FIN_DE_PROGRAMA, &g);
	return (EXIT_SUCCESS);
}

void	ft_where_is(t_so_long *g)
{
	int	i;

	i = 0;
	if (g->map[g->pos[1]][g->pos[0]] == 'X')
		ft_exit_free(FIN_DE_PROGRAMA, g);
	if (g->map[g->pos[1]][g->pos[0]] == 'C')
	{
		g->map[g->pos[1]][g->pos[0]] = 'P';
		ft_pain_colect(g);
	}
	if (g->map[g->pos[1]][g->pos[0]] == 'E' && !g->egg)
		ft_exit_free(FIN_DE_PROGRAMA, g);
}

void	ft_exit_free(int nb_error, t_so_long *game)
{
	if (nb_error == EXTENSION_NO_BER)
		exit(write(1, "\n[ERROR]La extencion no es \".ber\".\n\n", 37));
	if (nb_error == FIN_DE_PROGRAMA)
	{
		while (--game->h)
			free(game->map[game->h]);
		ft_clean_image(game);
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		exit(write(1, "\n[FIN_DE_PROGRAMA]\n\n", 21));
	}
	if (nb_error == MAPA_NO_CORRECTO)
		exit(write(1, "\n[ERROR]Mapa no correcto.\n\n", 28));
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
