/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:59:41 by ahaidour          #+#    #+#             */
/*   Updated: 2023/04/07 17:49:08 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(t_node *stack)
{
	t_node	*curr;
	int		tmp;

	curr = stack;
	while (stack != NULL && curr->next != NULL)
	{
		if (curr->content > curr->next->content)
		{
			tmp = 0;
			break ;
		}
		else
			tmp = 1;
		curr = curr->next;
	}
	return (tmp);
}

int	min_index(t_node *stack_a)
{
	int	index;
	int	min;
	int	i;

	index = 0;
	i = 0;
	min = stack_a->content;
	while (stack_a != NULL)
	{
		if (min > stack_a->content)
		{
			min = stack_a->content;
			i = index;
		}
		stack_a = stack_a->next;
		index++;
	}
	return (i);
}
