/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:59:41 by ahaidour          #+#    #+#             */
/*   Updated: 2023/04/17 17:29:00 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(t_lst *stack)
{
	t_lst	*curr;
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

int	min_index(t_lst *stack_a)
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

int	max_index(t_lst *stack_a)
{
	int	index;
	int	max;
	int	i;

	index = 0;
	i = 0;
	max = stack_a->content;
	while (stack_a != NULL)
	{
		if (max < stack_a->content)
		{
			max = stack_a->content;
			i = index;
		}
		stack_a = stack_a->next;
		index++;
	}
	return (i);
}
