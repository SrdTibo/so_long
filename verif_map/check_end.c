/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:00:12 by tserdet           #+#    #+#             */
/*   Updated: 2023/02/10 10:47:46 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	pos_x(void)
{
	char	**map;
	int		y;
	int		x;

	map = map_to_tab();
	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
				return (y);
			x++;
		}
		x = 0;
		y++;
	}
	return (-1);
}

int	pos_y(int x)
{
	int		i;
	char	**map;

	i = 0;
	map = map_to_tab();
	while (map[x][i] != 'P')
		i++;
	return (i);
}

void	f_fill(char **tab, int row, int col, t_point *compt)
{
	int	nbr_l;
	int	nbr_c;

	nbr_l = nmbr_lines_map();
	nbr_c = nmbr_columns_map();
	if (row < 0 || col < 0 || row >= nbr_l || col >= nbr_c)
		return ;
	if (tab[row][col] == 'E' || tab[row][col] == 'C')
		compt->x += 1;
	if (tab[row][col] == '1' || tab[row][col] == 'G')
		return ;
	else
	{
		tab[row][col] = '1';
		f_fill(tab, row -1, col, compt);
		f_fill(tab, row +1, col, compt);
		f_fill(tab, row, col - 1, compt);
		f_fill(tab, row, col + 1, compt);
	}
}

int	flood_fill(char **tab, t_point begin, t_point *compt)
{
	f_fill(tab, begin.x, begin.y, compt);
	return (1);
}

int	check_end(void)
{
	t_point	begin;
	t_point	*compt;
	char	**map;

	compt = malloc(sizeof(t_point));
	map = map_to_tab();
	compt->x = 0;
	begin.x = pos_x();
	begin.y = pos_y(begin.x);
	flood_fill(map, begin, compt);
	if (compt->x != (nmbr_c() + 1))
	{
		ft_printf("%s", "Error\nSortie ou items sont inaccessible");
		free (compt);
		return (0);
	}
	free (compt);
	ft_printf("%s\n", "End : OK");
	return (1);
}
