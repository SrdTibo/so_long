/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:59:42 by tserdet           #+#    #+#             */
/*   Updated: 2022/07/23 12:04:14 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int		lenght;
	int		i;

	i = 0;
	lenght = 0;
	while (dest[lenght] != '\0')
	{
		lenght++;
	}
	while (src[i])
	{
		dest[lenght] = src[i];
		i++;
		lenght++;
	}
	dest[lenght] = '\0';
	return (dest);
}
