/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:52:49 by ahaidour          #+#    #+#             */
/*   Updated: 2023/05/01 16:41:49 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	informations(t_arr *arr)
{
	t_info	inf;

	inf.mid = arr->size / 2 - 1;
	if (arr->size <= 100)
		inf.div = 5;
	else
		inf.div = 11;
	inf.offset = arr->size / inf.div;
	inf.start = inf.mid - inf.offset;
	inf.end = inf.mid + inf.offset;
	return (inf);
}

int	max_stack_b(t_lst *stack_b)
{
	int	max;

	max = stack_b->content;
	while (stack_b)
	{
		if (stack_b->content > max)
			max = stack_b->content;
		stack_b = stack_b->next;
	}
	return (max);
}

int	look_for_next(t_lst *stack, int index)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == index)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}

int	get_index(t_arr arr, int content)
{
	int	index;

	index = 0;
	while (index < arr.size)
	{
		if (arr.table[index] == content)
			return (index);
		index++;
	}
	return (index);
}

void	give_index(t_lst **stack, t_arr arr)
{
	t_lst	*head;

	head = *stack;
	while ((*stack) != NULL)
	{
		(*stack)->index = get_index(arr, (*stack)->content);
		(*stack) = (*stack)->next;
	}
	*stack = head;
}
