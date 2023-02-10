/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:16:37 by tserdet           #+#    #+#             */
/*   Updated: 2023/02/10 10:53:29 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*map_to_char(void)
{
	int		fd;
	char	*line;
	char	*map_line;
	int		i;
	int		x;

	fd = open("map.ber", O_RDONLY);
	i = nmbr_columns_map() * nmbr_lines_map();
	map_line = malloc(sizeof(char) * (i + 1));
	i = 0;
	x = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (line[x] != '\0')
			map_line[i++] = line[x++];
		x = 0;
		free(line);
	}
	map_line[i] = '\0';
	close(fd);
	return (map_line);
}

char	**map_to_tab(void)
{
	char	*map_line;
	char	**map_tab;

	map_line = map_to_char();
	map_tab = ft_split(map_line, '\n');
	return (map_tab);
}
