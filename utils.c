/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:26:10 by ahaidour          #+#    #+#             */
/*   Updated: 2023/05/01 15:26:18 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sw(t_lst *stack, char *s)
{
	int	x;

	if (!stack)
		return ;
	x = stack->content;
	stack->content = stack->next->content;
	stack->next->content = x;
	if (s)
		ft_printf("%s\n", s);
}

void	swap_both(t_lst *satck_a, t_lst *stack_b)
{
	sw(satck_a, NULL);
	sw(stack_b, NULL);
	ft_printf("%s\n", "ss");
}

void	p(t_lst **from, t_lst **to, char *s)
{
	t_lst	*tmp;

	if (!(*from))
		return ;
	tmp = (*from)->next;
	ft_lstadd_front(to, *from);
	*from = tmp;
	ft_printf("%s\n", s);
}

void	r(t_lst **stack, char *s)
{
	t_lst	*temp;

	if (!(*stack))
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
	if (s)
		ft_printf("%s\n", s);
}

void	rotate_both(t_lst **stack_a, t_lst **stack_b)
{
	r(stack_a, NULL);
	r(stack_b, NULL);
	ft_printf("%s\n", "rr");
}
