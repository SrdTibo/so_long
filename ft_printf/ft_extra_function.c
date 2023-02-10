/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:47:53 by tserdet           #+#    #+#             */
/*   Updated: 2023/01/19 10:29:12 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nombre_chiffre(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n > 0)
	{
		count++;
		n = n / 16;
	}
	return (count);
}

int	ft_nombre_chiffre_p(unsigned long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n > 0)
	{
		count++;
		n = n / 16;
	}
	return (count + 2);
}

int	verification_hexa(int *verification)
{
	*verification = -1;
	return (0);
}
