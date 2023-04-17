/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:54:31 by ahaidour          #+#    #+#             */
/*   Updated: 2023/04/17 17:29:00 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_lst **stack)
{
	t_lst	*end_1;
	t_lst	*last;
	t_lst	*head;

	if (stack != NULL)
	{
		end_1 = *stack;
		head = *stack;
		last = mylst_last(*stack);
		while (end_1->next->next != NULL)
			end_1 = end_1->next;
		end_1->next = NULL;
		mylstadd_front(stack, last);
		ft_printf("rra\n");
	}
}

void	rrb(t_lst **stack)
{
	t_lst	*end_1;
	t_lst	*last;
	t_lst	*head;

	if (stack != NULL)
	{
		end_1 = *stack;
		head = *stack;
		last = mylst_last(*stack);
		while (end_1->next->next != NULL)
			end_1 = end_1->next;
		end_1->next = NULL;
		mylstadd_front(stack, last);
		ft_printf("rrb\n");
	}
}

void	rrr(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*end_1;
	t_lst	*last;
	t_lst	*head;

	if (stack_a != NULL)
	{
		end_1 = *stack_a;
		head = *stack_a;
		last = mylst_last(*stack_a);
		while (end_1->next->next != NULL)
			end_1 = end_1->next;
		end_1->next = NULL;
		mylstadd_front(stack_a, last);
	}
	if (stack_b != NULL)
	{
		end_1 = *stack_b;
		head = *stack_b;
		last = mylst_last(*stack_b);
		while (end_1->next->next != NULL)
			end_1 = end_1->next;
		end_1->next = NULL;
		mylstadd_front(stack_b, last);
	}
	ft_printf("rrr\n");
}
