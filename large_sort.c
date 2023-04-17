/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:30:53 by ahaidour          #+#    #+#             */
/*   Updated: 2023/04/16 17:45:28 by ahaidour         ###   ########.fr       */
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

int	*fill_sort_array(t_node *stack_a, int size)
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

int find_in_range(t_node **stack_a, t_node **stack_b, int size)
{
	int	*arr;
	int i = 0;
	int div = 8;
	int	mid = size / 2 - 1;
	int	offset = size / div;
	int	start = mid - offset;
	int	end = mid + offset;
	arr = fill_sort_array(*stack_a, size);
	while (mylst_size(*stack_a) != 0)
	{
		while (/* condition */)
		{

		}
		if (!((*stack_a)->content >= arr[start] && (*stack_a)->content <= arr[end]))
		{
			ra(stack_a);
		}
		if ((*stack_a)->content >= arr[start] && (*stack_a)->content <= arr[end])
		{
			pb(stack_a, stack_b);
		}
	}
	return (i);
}

void	large_sort_100(t_node **stack_a, t_node **stack_b, int size)
{
	int i;
	int div = 8;
	int	mid = size / 2 - 1;
	int	offset = size / div;
	int	start = mid - offset;
	int	end = mid + offset;
	i = find_in_range(stack_a, stack_b, size);

		if (i < (start - end))
		{
			printf("labas\n");
		}
		// printf("content = %d\n", (*stack_a)->content);
			// (*stack_a) = (*stack_a)->next;
	}

// int i;
	// i = 0;
	// while (i < size)
	// {
	// 	printf("%d\n", arr[i]);
	// 	i++;
	// }
