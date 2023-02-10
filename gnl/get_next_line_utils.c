/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:50:38 by tserdet           #+#    #+#             */
/*   Updated: 2023/01/10 12:01:21 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero_gnl(void *s, size_t n)
{
	size_t	i;
	char	*chaine;

	chaine = s;
	i = 0;
	while (i < n)
	{
		chaine[i] = 0;
		i++;
	}
}

void	*ft_calloc_gnl(size_t elementCount, size_t elementSize )
{
	char	*pointeur;

	pointeur = (void *) malloc(elementCount * elementSize);
	if (!pointeur)
		return (NULL);
	ft_bzero_gnl(pointeur, (elementCount * elementSize));
	return (pointeur);
}

int	check_slash_n_gnl(char *stat)
{
	int	i;

	i = 0;
	if (!stat)
		return (0);
	while (stat[i] != '\0')
	{
		if (stat[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	else
	{
		while (str[i])
			i++;
		return (i);
	}
}

char	*ft_strjoin_gnl(char *s1, char *buf)
{
	int		i;
	int		t;
	int		lenght;
	char	*pointeur;

	i = 0;
	t = 0;
	lenght = ft_strlen_gnl(s1) + ft_strlen_gnl(buf);
	pointeur = ft_calloc_gnl(sizeof(char) + 1, lenght);
	if (!pointeur)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i])
		{
			pointeur[i] = s1[i];
			i++;
		}
	}
	while (buf[t])
		pointeur[i++] = buf[t++];
	pointeur[i] = '\0';
	if (s1)
		free(s1);
	return (pointeur);
}
