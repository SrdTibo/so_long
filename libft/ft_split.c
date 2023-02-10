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

static	char	**ft_free_malloc(char **tab, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

static	int	ft_alloc_nb_col(const char *s, char c)
{
	int	i;
	int	compt;

	i = 0;
	compt = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			compt += 1;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (compt);
}

static	char	**ft_alloc_taille_totale(const char *s, char c, char **tab)
{
	int	i;
	int	compteur;
	int	j;

	i = -1;
	j = 0;
	compteur = 0;
	while (s[++i])
	{
		if (s[i] != c)
			compteur++;
		if (((s[i - 1] != c && i > 0) && s[i] == c)
			|| (s[i + 1] == '\0' && s[i] != c))
		{
			tab[j] = malloc(sizeof(char) * (compteur + 1));
			if (tab[j] == NULL)
				return (ft_free_malloc(tab, j));
			compteur = 0;
			j++;
		}
	}
	return (tab);
}

static	char	**ft_alloc_mots(const char *s, char c, char **tab)
{
	int	i;
	int	j;
	int	compteur;

	i = 0;
	j = 0;
	compteur = 0;
	while (s[i])
	{
		if (s[i] != c)
			tab[j][compteur++] = s[i];
		else if (s[i - 1] != c && i > 0)
		{
			tab[j][compteur] = 0;
			j++;
			compteur = 0;
		}
		if (s[i + 1] == '\0' && s[i] != c)
			tab[j][compteur] = 0;
		i++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		taille;

	if (s == NULL)
		return (NULL);
	taille = ft_alloc_nb_col(s, c);
	if (!*s)
	{
		tab = malloc(sizeof(char *) * 1);
		if (tab == NULL)
			return (NULL);
		tab[0] = 0;
		return (tab);
	}
	tab = malloc(sizeof(char *) * (taille + 1));
	if (tab == NULL)
		return (NULL);
	tab = ft_alloc_taille_totale(s, c, tab);
	if (tab == NULL)
		return (NULL);
	tab = ft_alloc_mots(s, c, tab);
	tab[taille] = NULL;
	return (tab);
}
