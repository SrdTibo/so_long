/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:10:27 by tserdet           #+#    #+#             */
/*   Updated: 2022/11/02 09:26:57 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_strlenn(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	t;
	size_t	len_needle;

	len_needle = ft_strlenn(needle);
	i = 0;
	t = 0;
	if (len_needle <= 0)
		return ((char *)&haystack[t]);
	while (i < len && haystack[i])
	{
		if (needle[t] == haystack[i])
		{
			while (needle[t] && needle[t] == haystack[i + t] && (i + t) < len)
				t++;
		}
		if (t == len_needle)
			return ((char *)&haystack[i]);
		i++;
	t = 0;
	}
	return (0);
}
