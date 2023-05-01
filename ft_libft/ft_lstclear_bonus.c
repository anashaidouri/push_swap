/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:21:21 by gloukas           #+#    #+#             */
/*   Updated: 2023/05/01 14:01:23 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_lst **lst, void (*del)(void *))
{
	t_lst	*p;

	if (!*lst || !lst || !del)
		return ;
	p = *lst;
	while (p)
	{
		p = p->next;
		ft_lstdelone(*lst, del);
		*lst = p;
	}
}
