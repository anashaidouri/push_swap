/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:30:53 by ahaidour          #+#    #+#             */
/*   Updated: 2023/04/17 17:29:00 by ahaidour         ###   ########.fr       */
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
		j = i + 1;
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

int	*fill_sort_array(t_lst *stack_a, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * (size + 1));
	i = 0;
	while (stack_a != NULL)
	{
		arr[i] = stack_a->content;
		i++;
		stack_a = stack_a->next;
	}
	sort_arr(arr, size);
	return (arr);
}

void	find_in_range(t_lst **stack_a, t_lst **stack_b, t_all a)
{
	int	*arr;

	arr = fill_sort_array(*stack_a, a.size);
	while (mylst_size(*stack_a) != 0)
	{
		if (!((*stack_a)->content >= arr[a.start]
				&& (*stack_a)->content <= arr[a.end]))
		{
			ra(stack_a);
		}
		if ((*stack_a)->content >= arr[a.start]
			&& (*stack_a)->content <= arr[a.end])
		{
			pb(stack_a, stack_b);
		}
	}
}

void	large_sort_100(t_lst **stack_a, t_lst **stack_b, t_all *a)
{
	a->div = 8;
	a->mid = a->size / 2 - 1;
	a->offset = a->size / a->div;
	a->start = a->mid - a->offset;
	a->end = a->mid + a->offset;
	find_in_range(stack_a, stack_b, *a);
	// printf("content = %d\n", (*stack_a)->content);
	// (*stack_a) = (*stack_a)->next;
}

// int	i;
// i = 0;
// while (i < a.size)
// {
// 	printf("%d\n", arr[i]);
// 	i++;
// }
// exit(0);
