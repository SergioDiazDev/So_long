/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:51:43 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/03 18:00:19 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "../Get_Next_Line/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
//open
# include <fcntl.h>
//Defines
# define S 64
//REVISAR CONTROL DE ERRORES
# define EXTENSION_NO_BER -1
# define FIN_DE_PROGRAMA	-2
# define MAPA_NO_CORRECTO -3

//struct
typedef struct s_so_long
{
	int				w;
	int				h;
	int				steps;
	int				pos[2];
	char			**map;
	char			*temp;
	mlx_t			*mlx;
	mlx_image_t		*str;
	mlx_image_t		*bg;
	mlx_texture_t	*t_bg;
	mlx_image_t		*egg;
	mlx_texture_t	*t_egg;
	mlx_image_t		*mine;
	mlx_texture_t	*t_mine;
	mlx_image_t		*player;
	mlx_texture_t	*t_player;
	mlx_image_t		*coral;
	mlx_texture_t	*t_coral;
	mlx_image_t		*sushi;
	mlx_texture_t	*t_sushi;
	mlx_image_t		*rocket;
	mlx_texture_t	*t_rocket;

}	t_so_long;
//so_long_utils
int		ft_memcmp(char *str1, char *str2, int n);
char	*ft_loadstr(long n, long size);
char	*ft_itoa(long n);
//paint_map
void	ft_pain_map(t_so_long *g);
void	ft_pain_colect(t_so_long *g);
void	ft_open_exit(t_so_long *g);
//main.c
void	ft_exit_free(int nb_error, t_so_long *game);
void	ft_where_is(t_so_long *g);
void	ft_clean_image(t_so_long *game);
void	ft_leaks(void);
//hooks.c
void	ft_hook(mlx_key_data_t keydata, void *param);
void	ft_hook_2(mlx_key_data_t keydata, t_so_long *g);
//init_so_long
void	ft_init_so_long(t_so_long *game);
//read_map
void	ft_read_map(t_so_long *game, char *name_map);
void	ft_read_map2(t_so_long *g, char *name_map);
//correct_map
void	ft_correct_map(t_so_long *g);
int		all_is_one(char *str);
#endif
