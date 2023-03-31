/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 13:10:33 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/31 15:08:18 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_so_long(t_so_long *game)
{
	game->mlx = mlx_init(game->width * 64, game->height * 64, "so_long", false);
	if (!game->mlx)
		exit(write(1, "\n[ERROR]: No se pudo crear MLX\n\n", 33));
	game->t_bg = mlx_load_png("img/bg.png");
	game->t_mine = mlx_load_png("img/mine.png");
	game->t_player = mlx_load_png("img/player.png");
	game->bg = mlx_texture_to_image(game->mlx, game->t_bg);
	game->mine = mlx_texture_to_image(game->mlx, game->t_mine);
	game->player = mlx_texture_to_image(game->mlx, game->t_player);
}