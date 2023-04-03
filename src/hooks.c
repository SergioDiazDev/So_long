/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:34:30 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/03 17:49:27 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_so_long			*g;

	g = (t_so_long *) param;
	ft_where_is(g);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_exit_free(FIN_DE_PROGRAMA, g);
	if (g->map[g->pos[1] - 1][g->pos[0]] != '1')
	{
		if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		{
			g->player->instances[0].y -= S;
			g->pos[1]--;
			g->steps++;
		}
	}
	if (g->map[g->pos[1] + 1][g->pos[0]] != '1')
	{
		if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		{
			g->player->instances[0].y += S;
			g->pos[1]++;
			g->steps++;
		}
	}
	ft_hook_2(keydata, g);
}

void	ft_hook_2(mlx_key_data_t keydata, t_so_long *g)
{
	if (g->map[g->pos[1]][g->pos[0] - 1] != '1')
	{	
		if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		{
			g->player->instances[0].x -= S;
			g->pos[0]--;
			g->steps++;
		}
	}
	if (g->map[g->pos[1]][g->pos[0] + 1] != '1')
	{
		if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		{
			g->player->instances[0].x += S;
			g->pos[0]++;
			g->steps++;
		}
	}
	mlx_delete_image(g->mlx, g->str);
	g->temp = ft_itoa(g->steps);
	g->str = mlx_put_string(g->mlx, g->temp, g->w * S - 32, g->h * S - 20);
	free(g->temp);
}
