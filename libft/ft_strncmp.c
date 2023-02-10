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

int	ft_strncmp( const char *first, const char *second, size_t length )
{
	size_t					i;
	const unsigned char		*first1;
	const unsigned char		*first2;

	i = 0;
	first1 = (const unsigned char *)first;
	first2 = (const unsigned char *)second;
	while ((i != length) && (first1[i] != '\0' || first2[i] != '\0'))
	{
		if (first1[i] < first2[i])
		{
			return (-1);
		}
		if (first1[i] > first2[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}
