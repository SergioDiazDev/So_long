/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:12:53 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/01 12:57:10 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pain_map(t_so_long *g)
{
	int	i;
	int	j;

	i = 0;
	while (i <= g->height - 1)
	{
		j = 0;
		while (j <= g->width - 1)
		{
			mlx_image_to_window(g->mlx, g->bg, j * BLOCK, i * BLOCK);
			if (g->map[i][j] == '1')
				mlx_image_to_window(g->mlx, g->coral, j * BLOCK, i * BLOCK);
			else if (g->map[i][j] == 'C')
				mlx_image_to_window(g->mlx, g->sushi, j * BLOCK, i * BLOCK);
			else if (g->map[i][j] == 'P')
				mlx_image_to_window(g->mlx, g->player, j * BLOCK, i * BLOCK);
			else if (g->map[i][j] == 'E')
				mlx_image_to_window(g->mlx, g->mine, j * BLOCK, i * BLOCK);
			else if (g->map[i][j] == 'S')
				mlx_image_to_window(g->mlx, g->egg, j * BLOCK, i * BLOCK);
			j++;
		}
		i++;
	}
}
