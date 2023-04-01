/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 13:10:33 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/01 13:12:48 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_so_long(t_so_long *g)
{
	g->mlx = mlx_init(g->width * BLOCK, g->height * BLOCK, "so_long", false);
	if (!g->mlx)
		exit(write(1, "\n[ERROR]: No se pudo crear MLX\n\n", 33));
	g->t_bg = mlx_load_png("img/bg.png");
	g->t_egg = mlx_load_png("img/egg.png");
	g->t_mine = mlx_load_png("img/mine.png");
	g->t_coral = mlx_load_png("img/coral.png");
	g->t_sushi = mlx_load_png("img/sushi.png");
	g->t_player = mlx_load_png("img/player.png");
	g->t_rocket = mlx_load_png("img/rocket.png");
	g->bg = mlx_texture_to_image(g->mlx, g->t_bg);
	g->egg = mlx_texture_to_image(g->mlx, g->t_egg);
	g->mine = mlx_texture_to_image(g->mlx, g->t_mine);
	g->coral = mlx_texture_to_image(g->mlx, g->t_coral);
	g->sushi = mlx_texture_to_image(g->mlx, g->t_sushi);
	g->player = mlx_texture_to_image(g->mlx, g->t_player);
	g->rocket = mlx_texture_to_image(g->mlx, g->t_rocket);
}
