/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:10:28 by tserdet           #+#    #+#             */
/*   Updated: 2023/02/10 10:42:07 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	launch_verif(void)
{
	int	result;

	result = verif_basic();
	if (result == 0)
		return (0);
	result = verif_wall();
	if (result == 0)
		return (0);
	result = check_end();
	if (result == 0)
		return (0);
	return (1);
}

int32_t	main(void)
{
	int			width;
	int			height;
	t_graphic	*graph;

	graph = malloc(sizeof(t_graphic));
	width = (nmbr_columns_map() - 1) * 64;
	height = nmbr_lines_map() * 64;
	graph->mlx = mlx_init(width, height, "Test", true);
	if (!graph->mlx)
		exit(EXIT_FAILURE);
	if (launch_verif() == 0)
		return (0);
	display_map(graph);
	player_move(graph);
	mlx_loop(graph->mlx);
	mlx_terminate(graph->mlx);
	free(graph);
	return (EXIT_SUCCESS);
}
