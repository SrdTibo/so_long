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

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*pointeur;
	int		taille;

	i = 0;
	taille = ft_strleon(s1);
	pointeur = malloc(taille * sizeof(char) + 1);
	if (pointeur == NULL)
		return (NULL);
	while (s1[i])
	{
		pointeur[i] = s1[i];
		i++;
	}
	pointeur[i] = '\0';
	return (pointeur);
}
