/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:58:54 by ahaidour          #+#    #+#             */
/*   Updated: 2023/05/06 15:29:09 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_lst **stack_a)
{
	t_lst	*last;
	t_lst	*p;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = *stack_a;
	while (last->next)
	{
		p = last;
		last = last->next;
	}
	p->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
}

void	rrb(t_lst **stack_b)
{
	t_lst	*last;
	t_lst	*p;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = *stack_b;
	while (last->next)
	{
		p = last;
		last = last->next;
	}
	p->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
}

void	sa(t_lst *stack_a)
{
	int	x;

	if (!stack_a || stack_a->next == NULL)
		return ;
	x = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = x;
}

void	sb(t_lst *stack_b)
{
	int	x;

	if (!stack_b || stack_b->next == NULL)
		return ;
	x = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = x;
}

void	ss(t_lst *stack_a, t_lst *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
