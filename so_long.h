/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:04:31 by tserdet           #+#    #+#             */
/*   Updated: 2023/02/10 11:19:12 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "MLX42-C/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	i;
}				t_point;
typedef struct s_graphic
{
	int				compt_move;
	int				coin_get;
	mlx_image_t		*img;
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	char			**map;
	int				a;
	int				b;
}				t_graphic;
int		verif_basic(void);
void	depart(void);
int		is_regular(char **map);
int		nmbr_lines_map(void);
int		nmbr_columns_map(void);
char	**map_to_tab(void);
int		verif_wall(void);
int		nmbr_c(void);
int		check_end(void);
void	load_fish(mlx_t *mlx, int x, int y);
void	load_fisher(t_graphic *graph, int x, int y);
void	load_iceyrocks(mlx_t *mlx, int x, int y);
void	load_snow(mlx_t *mlx, int x, int y);
void	load_water(mlx_t *mlx, int x, int y);
void	display_map(t_graphic *graph);
int		player_move(t_graphic *graph);
int		pos_x(void);
int		pos_y(int x);
int		verif_w(t_graphic *graph);
int		verif_s(t_graphic *graph);
int		verif_a(t_graphic *graph);
int		verif_d(t_graphic *graph);
#endif