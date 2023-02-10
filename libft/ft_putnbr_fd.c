/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:54:02 by tserdet           #+#    #+#             */
/*   Updated: 2022/07/23 16:23:56 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	convertionn(int p, int fd)
{
	char	n;

	n = 48 + p;
	write(fd, &n, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	o;
	int	p;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = n * -1;
		}
		if ((n > -1) && (n < 10))
			convertionn(n, fd);
		else
		{
			o = n / 10;
			p = n % 10;
			ft_putnbr_fd(o, fd);
			convertionn(p, fd);
		}
	}
}
