/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:12:53 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/03 12:29:52 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pain_map(t_so_long *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= g->height - 1)
	{
		j = -1;
		while (++j <= g->width - 1)
		{
			mlx_image_to_window(g->mlx, g->bg, j * SIZE, i * SIZE);
			if (g->map[i][j] == '1')
				mlx_image_to_window(g->mlx, g->coral, j * SIZE, i * SIZE);
			else if (g->map[i][j] == 'C')
			{
				mlx_image_to_window(g->mlx, g->sushi, j * SIZE, i * SIZE);
				
			}
			else if (g->map[i][j] == 'P')
			{
				g->pos[1] = i;
				g->pos[0] = j;
			}
			else if (g->map[i][j] == 'X')
				mlx_image_to_window(g->mlx, g->mine, j * SIZE, i * SIZE);
			else if (g->map[i][j] == 'E')
				mlx_image_to_window(g->mlx, g->egg, j * SIZE, i * SIZE);
		}
	}
	mlx_image_to_window(g->mlx, g->player, g->pos[0] * SIZE, g->pos[1] * SIZE);
}
