/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:15:40 by tserdet           #+#    #+#             */
/*   Updated: 2023/02/10 11:00:52 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_fish(mlx_t *mlx, int x, int y)
{
	t_graphic	*fish;

	fish = malloc(sizeof(t_graphic));
	fish->texture = mlx_load_png("sprites/FISH.png");
	if (!fish->texture)
		exit(EXIT_FAILURE);
	fish->image = mlx_texture_to_image(mlx, fish->texture);
	if (!fish->image)
		exit(EXIT_FAILURE);
	if (mlx_image_to_window(mlx, fish->image, x, y) < 0)
		exit(EXIT_FAILURE);
}

void	load_fisher(t_graphic *graph, int x, int y)
{
	graph->texture = mlx_load_png("sprites/FISHER.png");
	if (!graph->texture)
		exit(EXIT_FAILURE);
	graph->img = mlx_texture_to_image(graph->mlx, graph->texture);
	if (!graph->img)
		exit(EXIT_FAILURE);
	if (mlx_image_to_window(graph->mlx, graph->img, x, y) < 0)
		exit(EXIT_FAILURE);
}

void	load_iceyrocks(mlx_t *mlx, int x, int y)
{
	t_graphic	*rocks;

	rocks = malloc(sizeof(t_graphic));
	rocks->texture = mlx_load_png("sprites/ICEYROCKS.png");
	if (!rocks->texture)
		exit(EXIT_FAILURE);
	rocks->image = mlx_texture_to_image(mlx, rocks->texture);
	if (!rocks->image)
		exit(EXIT_FAILURE);
	if (mlx_image_to_window(mlx, rocks->image, x, y) < 0)
		exit(EXIT_FAILURE);
}

void	load_snow(mlx_t *mlx, int x, int y)
{
	t_graphic	*snow;

	snow = malloc(sizeof(t_graphic));
	snow->texture = mlx_load_png("sprites/SNOW.png");
	if (!snow->texture)
		exit(EXIT_FAILURE);
	snow->image = mlx_texture_to_image(mlx, snow->texture);
	if (!snow->image)
		exit(EXIT_FAILURE);
	if (mlx_image_to_window(mlx, snow->image, x, y) < 0)
		exit(EXIT_FAILURE);
}

void	load_water(mlx_t *mlx, int x, int y)
{
	t_graphic	*water;

	water = malloc(sizeof(t_graphic));
	water->texture = mlx_load_png("sprites/WATER.png");
	if (!water->texture)
		exit(EXIT_FAILURE);
	water->image = mlx_texture_to_image(mlx, water->texture);
	if (!water->image)
		exit(EXIT_FAILURE);
	if (mlx_image_to_window(mlx, water->image, x, y) < 0)
		exit(EXIT_FAILURE);
}
