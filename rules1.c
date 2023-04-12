/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:53:42 by ahaidour          #+#    #+#             */
/*   Updated: 2023/04/04 11:42:58 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack)
{
	t_node	*first;
	t_node	*temp;
	t_node	*last;

	if (stack != NULL)
	{
		first = *stack;
		temp = (*stack)->next;
		last = mylst_last(*stack);
		(*last).next = (first);
		(*first).next = NULL;
		(*stack) = temp;
		ft_printf("ra\n");
	}
}

void	rb(t_node **stack)
{
	t_node	*first;
	t_node	*temp;
	t_node	*last;

	if (stack != NULL)
	{
		first = *stack;
		temp = (*stack)->next;
		last = mylst_last(*stack);
		(*last).next = (first);
		(*first).next = NULL;
		(*stack) = temp;
		ft_printf("ra\n");
	}
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	t_node	*first;
	t_node	*temp;
	t_node	*last;

	if (stack_a != NULL)
	{
		first = *stack_a;
		temp = (*stack_a)->next;
		last = mylst_last(*stack_a);
		(*last).next = (first);
		(*first).next = NULL;
		(*stack_a) = temp;
	}
	if (stack_b != NULL)
	{
		first = *stack_b;
		temp = (*stack_b)->next;
		last = mylst_last(*stack_b);
		(*last).next = (first);
		(*first).next = NULL;
		(*stack_b) = temp;
	}
	ft_printf("rr\n");
}
