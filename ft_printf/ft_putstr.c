/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 01:00:40 by ahaidour          #+#    #+#             */
/*   Updated: 2022/11/05 03:07:07 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (*(str + i) != '\0')
		{
			write(1, str + i, 1);
			i++;
		}
	}
	if (str == NULL)
		i += ft_putstr("(null)");
	return (i);
}