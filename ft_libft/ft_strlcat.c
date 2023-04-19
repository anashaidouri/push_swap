/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:19:52 by ahaidour          #+#    #+#             */
/*   Updated: 2022/10/31 13:19:17 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ld;
	size_t	ls;

	ld = 0;
	ls = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (dstsize + ls);
	ld = ft_strlen(dst);
	if (dstsize == 0 || ld >= dstsize)
		return (dstsize + ls);
	i = 0;
	while (src[i] && (i < (dstsize - ld - 1)))
	{
		dst[ld + i] = src[i];
		i++;
	}
	dst[ld + i] = '\0';
	return (ld + ls);
}
