/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:26 by tserdet           #+#    #+#             */
/*   Updated: 2023/02/10 11:02:42 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_map_basic(mlx_t *mlx, int fd)
{
	t_point	coord;
	char	*line;

	coord.x = 0;
	coord.y = 0;
	coord.i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (line[coord.i] != '\0')
		{
			if (line[coord.i] == '1')
				load_iceyrocks(mlx, coord.x, coord.y);
			else
				load_snow(mlx, coord.x, coord.y);
			coord.x += 64;
			coord.i++;
		}
		coord.y += 64;
		coord.i = 0;
		coord.x = 0;
	}
}

void	display_map_exit(mlx_t *mlx, int fd)
{
	t_point	coord;
	char	*line;

	coord.x = 0;
	coord.y = 0;
	coord.i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (line[coord.i] != '\0')
		{
			if (line[coord.i] == 'E')
				load_water(mlx, coord.x, coord.y);
			coord.x += 64;
			coord.i++;
		}
		coord.y += 64;
		coord.i = 0;
		coord.x = 0;
	}
}

void	display_map_items(mlx_t *mlx, int fd)
{
	t_point	coord;
	char	*line;

	coord.x = 0;
	coord.y = 0;
	coord.i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (line[coord.i] != '\0')
		{
			if (line[coord.i] == 'C')
				load_fish(mlx, coord.x, coord.y);
			coord.x += 64;
			coord.i++;
		}
		coord.y += 64;
		coord.i = 0;
		coord.x = 0;
	}
}

void	display_map(t_graphic *graph)
{
	int	fd;

	fd = open("map.ber", O_RDONLY);
	display_map_basic(graph->mlx, fd);
	close(fd);
	fd = open("map.ber", O_RDONLY);
	display_map_items(graph->mlx, fd);
	close(fd);
	fd = open("map.ber", O_RDONLY);
	display_map_exit(graph->mlx, fd);
	close(fd);
}
