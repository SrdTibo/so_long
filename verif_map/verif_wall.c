/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:23:40 by tserdet           #+#    #+#             */
/*   Updated: 2023/02/02 11:19:44 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	f_and_l_wall(char **map)
{
	int	i;
	int	nmbr_line;

	i = 0;
	nmbr_line = nmbr_lines_map();
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[nmbr_line - 1][i] != '\0')
	{
		if (map[nmbr_line - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_regular(char **map)
{
	int	i;
	int	j;
	int	first_compteur;
	int	second_verif;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			j++;
		}
		if (i == 0 && j > 0)
			first_compteur = j;
		second_verif = j;
		if ((first_compteur != second_verif))
			return (0);
		i++;
		j = 0;
	}
	if (i < 3)
		return (0);
	return (1);
}

int	middle_lines(char **map)
{
	int	i;
	int	j;
	int	nmbr_columns;

	i = 1;
	j = 0;
	nmbr_columns = nmbr_columns_map();
	while (i < nmbr_lines_map())
	{
		if (map[i][j] != '1')
			return (0);
		while (j != nmbr_columns - 2)
			j++;
		if (map[i][j] != '1')
			return (0);
		i++;
		j = 0;
	}
	return (1);
}

int	verif_wall(void)
{
	char	**map;
	int		confirm;

	confirm = 0;
	map = map_to_tab();
	confirm += is_regular(map);
	confirm += f_and_l_wall(map);
	confirm += middle_lines(map);
	if (confirm != 3)
	{
		ft_printf("%s", "Error\nLa map n'est pas fermée!");
		return (0);
	}
	ft_printf("%s\n", "Murs : OK");
	return (1);
}
