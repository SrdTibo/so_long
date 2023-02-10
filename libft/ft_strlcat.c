/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>                +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:11:12 by tserdet           #+#    #+#             */
/*   Updated: 2022/11/01 10:03:12 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	taille_dest;

	i = 0;
	taille_dest = 0;
	while (dst[taille_dest] && taille_dest < size)
		taille_dest++;
	while (src[i] && size && i + taille_dest < size - 1)
	{
		dst[taille_dest + i] = src[i];
		i++;
	}
	if (taille_dest < size)
		dst[taille_dest + i] = '\0';
	i = 0;
	while (src[i])
			i++;
	return (taille_dest + i);
}
