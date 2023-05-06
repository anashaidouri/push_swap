/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:58:07 by ahaidour          #+#    #+#             */
/*   Updated: 2023/05/06 15:26:17 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_lst **stack_b, t_lst **stack_a)
{
	t_lst	*p;

	if (!(*stack_b))
		return ;
	p = (*stack_b)->next;
	ft_lstadd_front(stack_a, *stack_b);
	*stack_b = p;
}

void	pb(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*p;

	if (!(*stack_a))
		return ;
	p = (*stack_a)->next;
	ft_lstadd_front(stack_b, *stack_a);
	*stack_a = p;
}

void	ra(t_lst **stack_a)
{
	t_lst	*temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	ft_lstadd_back(stack_a, temp);
}

void	rb(t_lst **stack_b)
{
	t_lst	*temp;

	if (!(*stack_b) || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	ft_lstadd_back(stack_b, temp);
}

void	rr(t_lst **stack_a, t_lst **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
