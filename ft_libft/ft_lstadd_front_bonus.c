/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:19:03 by gloukas           #+#    #+#             */
/*   Updated: 2023/05/01 14:01:23 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_lst **lst, t_lst *new)
{
	if (!lst || !*lst)
	{
		*lst = new;
		(*lst)->next = NULL;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
