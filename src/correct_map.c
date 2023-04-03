/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:35:48 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/01 19:35:48 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_correct_map(t_so_long *g)
{
	int	i;

	i = 0;
	if (all_is_one(g->map[g->h - 1]) || all_is_one(g->map[0]))
		ft_exit_free(MAPA_NO_CORRECTO, g);
	while (++i < g->h)
	{
		if (g->map[i][0] != '1' || g->map[i][g->w - 1] != '1')
			ft_exit_free(MAPA_NO_CORRECTO, g);
	}
}

int	all_is_one(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '1')
			return (0);
	}
	return (1);
}

void	ft_map_solve(char **map, int i, int j, t_so_long *g)
{
	int	y;
	int	x;

	if (i < g->h && j < g->w)
	{
		map[i][j] = '2';
		if (map[i + 1][j] != '1' || map[i + 1][j] != 'X')
			ft_map_solve(map, ++i, j, g);
		if (map[i - 1][j] != '1' || map[i - 1][j] != 'X')
			ft_map_solve(map, --i, j, g);
		if (map[i][j + 1] != '1' || map[i][j + 1] != 'X')
			ft_map_solve(map, i, ++j, g);
		if (map[i][j - 1] != '1' || map[i][j - 1] != 'X')
			ft_map_solve(map, i, --j, g);
		y = -1;
		while (++y <= g->h - 1)
		{
			x = -1;
			while (++x <= g->w - 1)
			{
				printf("%d", map[y][x]);
			}
			printf("/n");
		}
	}
	printf("hola%d", g->h);
}
