/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:03:17 by tserdet           #+#    #+#             */
/*   Updated: 2023/02/10 11:07:47 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	verif_w(t_graphic *graph)
{
	if (graph->map[graph->a - 1][graph->b] == '1')
		return (0);
	if (graph->map[graph->a - 1][graph->b] == 'C')
	{
		graph->coin_get = graph->coin_get + 1;
		load_snow(graph->mlx, (graph->b) * 64, (graph->a - 1) * 64);
		mlx_delete_image(graph->mlx, graph->img);
		load_fisher(graph, (graph->b) * 64, (graph->a) * 64);
		graph->map[graph->a - 1][graph->b] = '0';
	}
	if (graph->map[graph->a - 1][graph->b] == 'E')
	{
		if (graph->coin_get == nmbr_c())
		{
			ft_printf("You won!");
			mlx_close_window(graph->mlx);
			return (0);
		}
	}
	graph->a = graph->a - 1;
	return (1);
}

int	verif_s(t_graphic *graph)
{
	if (graph->map[graph->a + 1][graph->b] == '1')
		return (0);
	if (graph->map[graph->a + 1][graph->b] == 'C')
	{
		graph->coin_get = graph->coin_get + 1;
		load_snow(graph->mlx, (graph->b) * 64, (graph->a + 1) * 64);
		mlx_delete_image(graph->mlx, graph->img);
		load_fisher(graph, (graph->b) * 64, (graph->a) * 64);
		graph->map[graph->a + 1][graph->b] = '0';
	}
	if (graph->map[graph->a + 1][graph->b] == 'E')
	{
		if (graph->coin_get == nmbr_c())
		{
			ft_printf("You won!");
			mlx_close_window(graph->mlx);
			return (0);
		}
	}
	graph->a = graph->a + 1;
	return (1);
}

int	verif_a(t_graphic *graph)
{
	if (graph->map[graph->a][graph->b - 1] == '1')
		return (0);
	if (graph->map[graph->a][graph->b - 1] == 'C')
	{
		graph->coin_get = graph->coin_get + 1;
		load_snow(graph->mlx, (graph->b - 1) * 64, (graph->a) * 64);
		mlx_delete_image(graph->mlx, graph->img);
		load_fisher(graph, (graph->b) * 64, (graph->a) * 64);
		graph->map[graph->a][graph->b - 1] = '0';
	}
	if (graph->map[graph->a][graph->b - 1] == 'E')
	{
		if (graph->coin_get == nmbr_c())
		{
			ft_printf("You won!");
			mlx_close_window(graph->mlx);
			return (0);
		}
	}
	graph->b = graph->b - 1;
	return (1);
}

int	verif_d(t_graphic *graph)
{
	if (graph->map[graph->a][graph->b + 1] == '1')
		return (0);
	if (graph->map[graph->a][graph->b + 1] == 'C')
	{
		graph->coin_get = graph->coin_get + 1;
		load_snow(graph->mlx, (graph->b + 1) * 64, (graph->a) * 64);
		mlx_delete_image(graph->mlx, graph->img);
		load_fisher(graph, (graph->b) * 64, (graph->a) * 64);
		graph->map[graph->a][graph->b + 1] = '0';
	}
	if (graph->map[graph->a][graph->b + 1] == 'E')
	{
		if (graph->coin_get == nmbr_c())
		{
			ft_printf("You won!");
			mlx_close_window(graph->mlx);
			return (0);
		}
	}
	graph->b = graph->b + 1;
	return (1);
}
