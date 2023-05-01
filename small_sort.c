/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:58:09 by ahaidour          #+#    #+#             */
/*   Updated: 2023/05/01 15:30:05 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test(t_lst **stack_a, int a, int b, int c)
{
	if (b > c && c > a)
	{
		rr(stack_a, "rra");
		sw(*stack_a, "sa");
	}
	else if (a > b && a < c)
		sw(*stack_a, "sa");
	else if (a < b && a > c)
		rr(stack_a, "rra");
	else if (a > b && a > c && b < c)
		r(stack_a, "ra");
	else if (a > b && a > c && b > c)
	{
		sw(*stack_a, "sa");
		rr(stack_a, "rra");
	}
}

void	sort_tree(t_lst **stack_a)
{
	t_lst	*head;
	t_lst	*second;
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

void	find_min_and_p(t_lst **stack_a, t_lst **stack_b, int size)
{
	int	i;

	while (size > 3)
	{
		i = min_index(*stack_a);
		if (i <= (size / 2))
		{
			while (i > 0)
			{
				r(stack_a, "ra");
				i--;
			}
			p(stack_a, stack_b, "pb");
		}
		else if (i > (size / 2))
		{
			while (i > 0)
			{
				r(stack_a, "ra");
				i--;
			}
			p(stack_a, stack_b, "pb");
		}
		size--;
	}
}

void	sort_five(t_lst **stack_a, t_lst **stack_b, int size)
{
	find_min_and_p(stack_a, stack_b, size);
	sort_tree(stack_a);
	while (size > 3)
	{
		p(stack_b, stack_a, "pa");
		size--;
	}
}
