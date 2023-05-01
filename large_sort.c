/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:30:53 by ahaidour          #+#    #+#             */
/*   Updated: 2023/05/01 16:43:19 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_arr(int *arr, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

t_arr	fill_sort_array(t_lst *stack_a)
{
	t_arr	arr;
	int		i;

	i = -1;
	arr.size = ft_lstsize(stack_a);
	arr.table = malloc(sizeof(int) * (arr.size + 1));
	while (stack_a)
	{
		arr.table[++i] = stack_a->content;
		stack_a = stack_a->next;
	}
	sort_arr(arr.table, arr.size);
	return (arr);
}

void	push_to_b(t_lst **stack_a, t_lst **stack_b, t_arr arr, t_info info)
{
	while (*stack_a)
	{
		while (is_full(*stack_a, arr, info))
		{
			if ((*stack_a)->content >= arr.table[info.start]
				&& (*stack_a)->content <= arr.table[info.end])
			{
				p(stack_a, stack_b, "pb");
				if ((*stack_b)->content < arr.table[info.mid])
					r(stack_b, "rb");
			}
			else
				r(stack_a, "ra");
		}
		info.start -= info.offset;
		info.end += info.offset;
		if (info.start < 0)
			info.start = 0;
		if (info.end >= arr.size)
			info.end = arr.size - 1;
	}
}

void	back_to_a(t_lst **stack_a, t_lst **stack_b, int size)
{
	while (*stack_b || !issorted(*stack_a))
	{
		if (*stack_b && (*stack_b)->index == (*stack_a)->index - 1)
			p(stack_b, stack_a, "pa");
		else if (ft_lstlast(*stack_a)->index == (*stack_a)->index - 1)
			rr(stack_a, "rra");
		else if (*stack_b && (ft_lstlast(*stack_a)->index == size - 1
				|| (*stack_b)->index > ft_lstlast(*stack_a)->index))
		{
			p(stack_b, stack_a, "pa");
			r(stack_a, "ra");
		}
		else if (ft_lstsize(*stack_b) > 1)
		{
			if (look_for_next(*stack_b, (*stack_a)->index
					- 1) <= ft_lstsize(*stack_b) / 2)
				r(stack_b, "rb");
			else
				rr(stack_b, "rrb");
		}
	}
}

void	large_sort(t_lst **stack_a, t_lst **stack_b)
{
	t_info	info;
	t_arr	table;
	int		max;

	table = fill_sort_array(*stack_a);
	give_index(stack_a, table);
	info = informations(&table);
	push_to_b(stack_a, stack_b, table, info);
	max = max_stack_b(*stack_b);
	info.position = get_pos(*stack_b, max);
	while (info.position-- > 0)
		r(stack_b, "rb");
	p(stack_b, stack_a, "pa");
	back_to_a(stack_a, stack_b, table.size);
	free(table.table);
}
