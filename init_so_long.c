/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 13:10:33 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/31 13:19:42 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_so_long(t_so_long *game)
{
	game->height = 1024;
	game->width = 1024;
	game->mlx = mlx_init(game->width, game->height, "so_long", false);
	if (!game->mlx)
		ft_exit_free(-1, game);
	game->t_bg = mlx_load_png("img/bg.png");
	game->t_mine = mlx_load_png("img/mine.png");
	game->t_player = mlx_load_png("img/player.png");
	game->bg = mlx_texture_to_image(game->mlx, game->t_bg);
	game->mine = mlx_texture_to_image(game->mlx, game->t_mine);
	game->player = mlx_texture_to_image(game->mlx, game->t_player);
}