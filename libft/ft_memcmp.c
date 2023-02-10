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

int	ft_memcmp( const void *pointer1, const void *pointer2, size_t size )
{
	const unsigned char	*string1;
	const unsigned char	*string2;
	size_t				i;

	string1 = (const unsigned char *) pointer1;
	string2 = (const unsigned char *) pointer2;
	i = 0;
	if (size == 0)
		return (0);
	while (i < size)
	{
		if (string1[i] != string2[i])
			return (string1[i] - string2[i]);
		i++;
	}
	return (0);
}
