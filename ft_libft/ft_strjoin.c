/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:53:13 by ahaidour          #+#    #+#             */
/*   Updated: 2023/05/06 17:16:59 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!s1)
		return(ft_strdup(s2));
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!new)
		return (NULL);
	while (s1[i])
		new[count++] = s1[i++];
	i = 0;
	new[count++] = ' ';
	while (s2[i])
		new[count++] = s2[i++];
	new[count] = '\0';
	// free(s1);
	return (new);
}

