/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:55:57 by ahaidour          #+#    #+#             */
/*   Updated: 2022/10/31 13:29:07 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	if (!s1 && len == 0)
		return (NULL);
	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		if (s1[i] == s2[j] && i < len)
		{
			while (s1[i + j] == s2[j] && (i + j) < len)
			{
				j++;
				if (s2[j] == '\0')
					return ((char *)(s1 + i));
			}
		}
		i++;
	}
	return (NULL);
}
