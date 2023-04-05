/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:56:57 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/05 16:59:49 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(t_so_long *g, char *name_map)
{
	int		size;
	int		fd;

	size = ft_strlen(name_map);
	if (ft_memcmp(&name_map[size - 4], ".ber", 4))
		ft_exit_free(EXTENSION_NO_BER, g);
	ft_read_map2(g, name_map);
	g->map = ft_calloc(sizeof(char *), g->h + 1);
	fd = open(name_map, O_RDONLY);
	size = 0;
	while (size != g->h)
		g->map[size++] = get_next_line(fd);
	close(fd);
	ft_min_map(g);
}

void	ft_read_map2(t_so_long *g, char *name_map)
{
	int		size;
	int		fd;

	fd = open(name_map, O_RDONLY);
	g->temp = get_next_line(fd);
	size = ft_strlen(g->temp) - 1;
	g->w = size;
	while (g->temp)
	{
		free(g->temp);
		g->temp = get_next_line(fd);
		if (ft_strlen(g->temp) - 1 != g->w && g->temp)
			ft_exit_free(MAPA_NO_CORRECTO, g);
		g->h++;
	}
	free(g->temp);
	close(fd);
	if (g->h == g->w || g->h <= 2 || g->w <= 2)
		ft_exit_free(MAPA_NO_CORRECTO, g);
}

void	ft_min_map(t_so_long *g)
{
	int	i;
	int	j;

	g->count_p = 0;
	g->count_e = 0;
	g->count_c = 0;
	i = -1;
	while (++i <= g->h - 1)
	{
		j = -1;
		while (++j <= g->w - 1)
		{
			if (g->map[i][j] == 'P')
				g->count_p++;
			else if (g->map[i][j] == 'E')
				g->count_e++;
			else if (g->map[i][j] == 'C')
				g->count_c++;
			else if (g->map[i][j] != 'X' && g->map[i][j] != '1'
			&& g->map[i][j] != '0')
				ft_exit_free(MAPA_NO_CORRECTO, g);
		}
	}
	if (g->count_e != 1 || g->count_p != 1 || g->count_c < 1)
		ft_exit_free(MAPA_NO_CORRECTO, g);
}
