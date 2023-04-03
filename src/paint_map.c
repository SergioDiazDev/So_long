/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:12:53 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/03 17:48:14 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pain_map(t_so_long *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= g->h - 1)
	{
		j = -1;
		while (++j <= g->w - 1)
		{
			mlx_image_to_window(g->mlx, g->bg, j * S, i * S);
			if (g->map[i][j] == '1')
				mlx_image_to_window(g->mlx, g->coral, j * S, i * S);
			else if (g->map[i][j] == 'C')
				mlx_image_to_window(g->mlx, g->sushi, j * S, i * S);
			else if (g->map[i][j] == 'P')
			{
				g->pos[1] = i;
				g->pos[0] = j;
			}
			else if (g->map[i][j] == 'X')
				mlx_image_to_window(g->mlx, g->mine, j * S, i * S);
			else if (g->map[i][j] == 'E')
				mlx_image_to_window(g->mlx, g->egg, j * S, i * S);
		}
	}
}

void	ft_pain_colect(t_so_long *g)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	mlx_delete_image(g->mlx, g->sushi);
	g->sushi = mlx_texture_to_image(g->mlx, g->t_sushi);
	while (++i <= g->h - 1)
	{
		j = -1;
		while (++j <= g->w - 1)
		{
			if (g->map[i][j] == 'C')
			{
				count++;
				mlx_image_to_window(g->mlx, g->sushi, j * S, i * S);
			}
		}
	}
	mlx_delete_image(g->mlx, g->player);
	g->player = mlx_texture_to_image(g->mlx, g->t_player);
	mlx_image_to_window(g->mlx, g->player, g->pos[0] * S, g->pos[1] * S);
	if (!count)
		ft_open_exit(g);
}

void	ft_open_exit(t_so_long *g)
{
	int	i;
	int	j;

	i = -1;
	mlx_delete_image(g->mlx, g->egg);
	g->rocket = mlx_texture_to_image(g->mlx, g->t_rocket);
	while (++i <= g->h - 1)
	{
		j = -1;
		while (++j <= g->w - 1)
		{
			if (g->map[i][j] == 'E')
			{
				mlx_image_to_window(g->mlx, g->rocket, j * S, i * S);
				g->egg = NULL;
			}
		}
	}
}
