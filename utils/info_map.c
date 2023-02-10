/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:55:35 by tserdet           #+#    #+#             */
/*   Updated: 2023/02/10 10:49:13 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	nmbr_columns_map(void)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	while (line[i] != '\0')
		i++;
	free(line);
	close(fd);
	return (i);
}

int	nmbr_lines_map(void)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open("map.ber", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

int	nmbr_c(void)
{
	int		fd;
	int		i;
	int		o;
	char	*line;

	i = 0;
	o = 0;
	fd = open("map.ber", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (line[o] != '\0')
		{
			if (line[o] == 'C')
				i++;
			o++;
		}
		o = 0;
		free(line);
	}
	close(fd);
	return (i);
}
