/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:54:02 by tserdet           #+#    #+#             */
/*   Updated: 2022/07/23 16:23:56 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *thestring)
{
	int	i;
	int	valeur;
	int	moins;

	i = 0;
	valeur = 0;
	moins = 0;
	while ((thestring[i] >= 9 && thestring[i] <= 13) || thestring[i] == 32)
		i++;
	if (thestring[i] == 43 || thestring[i] == 45)
	{
		if (thestring[i] == 45)
			moins++;
		i++;
	}
	while (thestring[i] && (thestring[i] >= 48 && thestring[i] <= 57))
	{
		valeur = ((valeur * 10) + (thestring[i] - 48));
		i++;
	}
	if (moins)
		valeur = -valeur;
	if (!(thestring[i] >= 48 && thestring[i] <= 57) && valeur == 0)
		return (0);
	return (valeur);
}
