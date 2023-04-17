/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:53:42 by ahaidour          #+#    #+#             */
/*   Updated: 2023/04/17 17:29:00 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_lst **stack)
{
	t_lst	*first;
	t_lst	*temp;
	t_lst	*last;

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

void	rb(t_lst **stack)
{
	t_lst	*first;
	t_lst	*temp;
	t_lst	*last;

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

void	rr(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*first;
	t_lst	*temp;
	t_lst	*last;

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
