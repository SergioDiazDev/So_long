/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:12:53 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/31 17:16:44 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pain_map(t_so_long *g)
{
	int	i;
	int	j;

	i = 0;
	while (i <= g->height)
	{
		j = 0;
		while (j <= g->width)
		{
			mlx_image_to_window(g->mlx, g->bg, i * BLOCK, j * BLOCK);
			j++;
		}
		i++;
	}
}