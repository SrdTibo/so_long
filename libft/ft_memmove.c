/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:11:40 by tserdet           #+#    #+#             */
/*   Updated: 2022/11/02 10:11:43 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t size)
{
	size_t		i;
	const char	*chaine_source;
	char		*chaine_dest;

	i = 0;
	chaine_dest = d;
	chaine_source = s;
	if (chaine_dest == 0 && chaine_source == 0)
		return (chaine_dest);
	if (chaine_dest > chaine_source)
	{
		while (size-- > 0)
			chaine_dest[size] = chaine_source[size];
	}
	else
	{
		while (i < size)
		{
			chaine_dest[i] = chaine_source[i];
			i++;
		}
	}
	return (chaine_dest);
}
