/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:18:36 by gloukas           #+#    #+#             */
/*   Updated: 2023/05/01 14:01:45 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_lst	*ft_lstnew(int content)
{
	t_lst	*n;

	n = (t_lst *)malloc(sizeof(t_lst));
	if (!n)
		return (NULL);
	n->content = content;
	n->next = NULL;
	return (n);
}
