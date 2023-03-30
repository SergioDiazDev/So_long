/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:51:43 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/03/30 16:22:50 by sdiaz-ru         ###   ########.fr       */
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
void	ft_read_map(char *name_map);

#endif
