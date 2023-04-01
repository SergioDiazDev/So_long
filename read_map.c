/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:56:57 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/01 13:57:33 by sdiaz-ru         ###   ########.fr       */
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
	g->map = ft_calloc(sizeof(char *), g->height + 1);
	fd = open(name_map, O_RDONLY);
	size = 0;
	while (size != g->height)
		g->map[size++] = get_next_line(fd);
	close(fd);
}

void	ft_read_map2(t_so_long *g, char *name_map)
{
	int		size;
	int		fd;

	fd = open(name_map, O_RDONLY);
	g->temp = get_next_line(fd);
	size = ft_strlen(g->temp) - 1;
	g->width = size;
	while (g->temp)
	{
		free(g->temp);
		g->temp = get_next_line(fd);
		if (ft_strlen(g->temp) - 1 != g->width && g->temp)
			ft_exit_free(MAPA_NO_CORRECTO, g);
		g->height++;
	}
	if (g->height == g->width || g->height <= 2 || g->width <= 2)
		ft_exit_free(MAPA_NO_CORRECTO, g);
	free(g->temp);
	close(fd);
}
