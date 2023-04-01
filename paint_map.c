/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:12:53 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/01 14:13:53 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pain_map(t_so_long *g)
{
	int	j;

	g->i = -1;
	while (++g->i <= g->height - 1)
	{
		j = -1;
		while (++j <= g->width - 1)
		{
			mlx_image_to_window(g->mlx, g->bg, j * SIZE, g->i * SIZE);
			if (g->map[g->i][j] == '1')
				mlx_image_to_window(g->mlx, g->coral, j * SIZE, g->i * SIZE);
			else if (g->map[g->i][j] == 'C')
				mlx_image_to_window(g->mlx, g->sushi, j * SIZE, g->i * SIZE);
			else if (g->map[g->i][j] == 'P')
			{
				g->pos[0] = g->i;
				g->pos[1] = j;
			}
			else if (g->map[g->i][j] == 'E')
				mlx_image_to_window(g->mlx, g->mine, j * SIZE, g->i * SIZE);
			else if (g->map[g->i][j] == 'S')
				mlx_image_to_window(g->mlx, g->egg, j * SIZE, g->i * SIZE);
		}
	}
	mlx_image_to_window(g->mlx, g->player, g->pos[0] * SIZE, g->pos[1] * SIZE);
}
