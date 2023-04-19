/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:01:08 by ahaidour          #+#    #+#             */
/*   Updated: 2022/10/31 12:21:34 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*psrc;
	char	*pdest;

	psrc = (char *)src;
	pdest = (char *)dst;
	if (psrc < pdest)
	{
		while (len--)
			pdest[len] = psrc[len];
		len++;
	}
	else
		ft_memcpy(pdest, psrc, len);
	return (dst);
}
