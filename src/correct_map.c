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

void	ft_map_solve(char **map, int i, int j)
{
	map[i][j] = '2';
	if (map[i + 1][j] == '0' || map[i + 1][j] == 'C' || map[i + 1][j] == 'E')
		ft_map_solve(map, i + 1, j);
	if (map[i - 1][j] == '0' || map[i - 1][j] == 'C' || map[i - 1][j] == 'E')
		ft_map_solve(map, i - 1, j);
	if (map[i][j + 1] == '0' || map[i][j + 1] == 'C' || map[i][j + 1] == 'E')
		ft_map_solve(map, i, j + 1);
	if (map[i][j - 1] == '0' || map[i][j - 1] == 'C' || map[i][j - 1] == 'E')
		ft_map_solve(map, i, j - 1);
}

void	ft_map_solve1(t_so_long *g)
{
	int	i;
	int	j;
	int	count_p;
	int	count_e;

	count_p = 0;
	count_e = 0;
	i = -1;
	while (++i <= g->h - 1)
	{
		j = -1;
		while (++j <= g->w - 1)
		{
			if (g->map[i][j] == 'E' || g->map[i][j] == 'C')
				ft_exit_free(MAPA_NO_CORRECTO, g);
		}
	}
	while (--g->h)
		free(g->map[g->h]);
	free(g->map[g->h]);
	free(g->map);
}
