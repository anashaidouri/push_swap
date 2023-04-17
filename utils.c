/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:47:48 by ahaidour          #+#    #+#             */
/*   Updated: 2023/04/17 17:29:00 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*mylst_new(int content)
{
	t_lst	*a;

	a = malloc(sizeof(t_lst));
	if (!a)
		return (NULL);
	a->content = content;
	a->next = NULL;
	return (a);
}

t_lst	*mylst_last(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	mylstadd_back(t_lst **lst, t_lst *new)
{
	if (*lst == NULL)
		*lst = new;
	else
	{
		mylst_last(*lst)->next = new;
	}
}

void	mylstadd_front(t_lst **lst, t_lst *new)
{
	if (*lst == NULL)
		*lst = mylst_new(new->content);
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

int	mylst_size(t_lst *lst)
{
	int	len;

	len = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

// int	main(void)
// {
// 	t_lst	*root;
// 	t_lst	*curr;
// 	t_lst	*curr2;
// 	t_lst	*i;

// 	root = mylst_new(1);
// 	curr = mylst_new(2);
// 	curr2 = mylst_new(3);
// 	mylstadd_back(&root, curr);
// 	mylstadd_back(&root, curr2);
// 	deallocate(&root);
// 	i = root;
// 	while (i != NULL)
// 	{
// 		printf("%d\n", i->content);
// 		i = i->next;
// 	}
// 	return (0);
// }
