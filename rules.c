/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:13:49 by ahaidour          #+#    #+#             */
/*   Updated: 2023/04/04 13:53:42 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack)
{
	int	tmp;

	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	ft_printf("sa\n");
}

void	sb(t_node **stack)
{
	int	tmp;

	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*help;

	if (stack_b == NULL)
		return ;
	help = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = help;
	ft_printf("pa\n");
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*help;

	if (stack_a == NULL)
		return ;
	help = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = help;
	ft_printf("pb\n");
}
