/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:58:09 by ahaidour          #+#    #+#             */
/*   Updated: 2023/04/07 17:49:01 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test(t_node **stack_a, int a, int b, int c)
{
	if (b > c && c > a)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (a > b && a < c)
		sa(stack_a);
	else if (a < b && a > c)
		rra(stack_a);
	else if (a > b && a > c && b < c)
		ra(stack_a);
	else if (a > b && a > c && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_tree(t_node **stack_a)
{
	t_node	*head;
	t_node	*second;
	int		a;
	int		b;
	int		c;

	if (stack_a != NULL)
	{
		head = *stack_a;
		second = head->next;
		a = head->content;
		b = second->content;
		c = second->next->content;
		test(stack_a, a, b, c);
	}
}

void	find_min_and_push(t_node **stack_a, t_node **stack_b, int size)
{
	int	i;

	while (size > 3)
	{
		i = min_index(*stack_a);
		if (i <= (size / 2))
		{
			while (i > 0)
			{
				ra(stack_a);
				i--;
			}
			pb(stack_a, stack_b);
		}
		else if (i > (size / 2))
		{
			while (i > 0)
			{
				ra(stack_a);
				i--;
			}
			pb(stack_a, stack_b);
		}
		size--;
	}
}

void	sort_five(t_node **stack_a, t_node **stack_b, int size)
{
	find_min_and_push(stack_a, stack_b, size);
	sort_tree(stack_a);
	while (size > 3)
	{
		pa(stack_a, stack_b);
		size--;
	}
}
