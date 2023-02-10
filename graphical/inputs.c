/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:00:21 by tserdet           #+#    #+#             */
/*   Updated: 2023/02/10 11:04:07 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_move(t_graphic *graph)
{
	ft_printf("Move: %d\n", graph->compt_move);
	graph->compt_move += 1;
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_graphic	*graph;

	graph = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(graph->mlx);
	if (mlx_is_key_down(graph->mlx, MLX_KEY_W) && verif_w(graph) == 1)
	{
		graph->img->instances[0].y -= (64 * 1);
		print_move(graph);
	}
	if (mlx_is_key_down(graph->mlx, MLX_KEY_S) && verif_s(graph) == 1)
	{
		graph->img->instances[0].y += (64 * 1);
		print_move(graph);
	}
	if (mlx_is_key_down(graph->mlx, MLX_KEY_A) && verif_a(graph) == 1)
	{
		graph->img->instances[0].x -= (64 * 1);
		print_move(graph);
	}
	if (mlx_is_key_down(graph->mlx, MLX_KEY_D) && verif_d(graph) == 1)
	{
		graph->img->instances[0].x += (64 * 1);
		print_move(graph);
	}
}

int	player_move(t_graphic *graph)
{
	t_point	*p_pos;

	p_pos = malloc(sizeof(t_point));
	p_pos->x = pos_x();
	p_pos->y = pos_y(p_pos->x);
	graph->a = p_pos->x;
	graph->b = p_pos->y;
	graph->map = map_to_tab();
	graph->coin_get = 0;
	load_fisher(graph, p_pos->y * 64, p_pos->x * 64);
	mlx_key_hook(graph->mlx, &ft_hook, graph);
	return (EXIT_SUCCESS);
}
