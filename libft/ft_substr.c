/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:10:27 by tserdet           #+#    #+#             */
/*   Updated: 2022/11/25 14:00:10 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strlenn(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	t;
	char	*pointeur;

	pointeur = NULL;
	i = 0;
	t = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlenn(s))
		len = 0;
	if (ft_strlenn(s) - start < len)
		len = ft_strlenn(s) - start;
	pointeur = (char *) malloc(sizeof(*s) * (len + 1));
	if (pointeur == NULL)
		return (0);
	while (s[i])
	{
		if (i >= start && t < len)
			pointeur[t++] = s[i];
		i++;
	}
	pointeur[t] = '\0';
	return (pointeur);
}
