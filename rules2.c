/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:24:10 by ahaidour          #+#    #+#             */
/*   Updated: 2023/05/01 15:30:19 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_lst **stack, char *s)
{
	t_lst	*last;
	t_lst	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	tmp->next = NULL;
	last->next = *stack;
	*stack = last;
	if (s)
		ft_printf("%s\n", s);
}

void	rrr(t_lst **stack_a, t_lst **stack_b)
{
	rr(stack_a, NULL);
	rr(stack_b, NULL);
	ft_printf("rrr");
}

int	issorted(t_lst *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	is_full(t_lst *stack_a, t_arr array, t_info info)
{
	while (stack_a)
	{
		if (stack_a->content >= array.table[info.start]
			&& stack_a->content <= array.table[info.end])
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	deallocate(t_lst **root)
{
	t_lst	*curr;
	t_lst	*temp;

	curr = *root;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	*root = NULL;
}
