/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:10:27 by tserdet           #+#    #+#             */
/*   Updated: 2022/11/02 17:11:40 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	const unsigned char	*string;
	size_t				i;

	string = (const unsigned char *) memoryBlock;
	i = 0;
	while (i < size)
	{
		if (string[i] == (const unsigned char) searchedChar)
			return ((void *)&string[i]);
		i++;
	}
	return (0);
}
