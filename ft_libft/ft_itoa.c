/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:34:20 by ahaidour          #+#    #+#             */
/*   Updated: 2022/10/31 13:53:57 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numbn(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	char	*tab;

	nb = n;
	i = numbn(n);
	tab = malloc(i * sizeof(char) + 1);
	if (!tab)
		return (NULL);
	if (nb < 0)
	{
		tab[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		tab[0] = '0';
	tab[i] = '\0';
	while (nb > 0)
	{
		tab[i - 1] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	return (tab);
}
