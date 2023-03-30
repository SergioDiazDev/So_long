/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:51:43 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/30 17:30:49 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_h
# define SO_LONG_h

# include <stdio.h>
# include <stdlib.h>
# include "Get_Next_Line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"
//open
# include <fcntl.h>

//so_long_utils
int	ft_memcmp(char *str1, char *str2, int n);
//main.c
void	ft_read_map(t_so_long game, char *name_map);
//
typedef struct	s_so_long
{
	int			width;
	int			height;
	char		**map;
	mlx_t		*mlx;
	mlx_image_t	*background;
	mlx_image_t	*mine;
	mlx_image_t	*player;

}	t_so_long;

#endif
