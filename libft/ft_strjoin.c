/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:54:02 by tserdet           #+#    #+#             */
/*   Updated: 2022/07/23 16:23:56 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_strleon(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		t;
	int		lenght;
	char	*pointeur;

	i = 0;
	t = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lenght = ft_strleon(s1) + ft_strleon(s2);
	pointeur = malloc(lenght * sizeof(char) + 1);
	if (pointeur == NULL)
		return (NULL);
	while (s1[i])
	{
		pointeur[i] = s1[i];
		i++;
	}
	while (s2[t])
		pointeur[i++] = s2[t++];
	pointeur[i] = '\0';
	return (pointeur);
}
