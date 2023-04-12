/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:47:48 by ahaidour          #+#    #+#             */
/*   Updated: 2023/03/26 13:27:10 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*mylst_new(int content)
{
	t_node	*a;

	a = malloc(sizeof(t_node));
	if (!a)
		return (NULL);
	a->content = content;
	a->next = NULL;
	return (a);
}

t_node	*mylst_last(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	mylstadd_back(t_node **lst, t_node *new)
{
	if (*lst == NULL)
		*lst = new;
	else
	{
		mylst_last(*lst)->next = new;
	}
}

void	mylstadd_front(t_node **lst, t_node *new)
{
	if (*lst == NULL)
		*lst = mylst_new(new->content);
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

int	mylst_size(t_node *lst)
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
// 	t_node	*root;
// 	t_node	*curr;
// 	t_node	*curr2;
// 	t_node	*i;

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
