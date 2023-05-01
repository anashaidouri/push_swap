/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:30:53 by ahaidour          #+#    #+#             */
/*   Updated: 2023/05/01 11:49:09 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_lst *lst)
{
	int	len;

	if (!lst)
		return (0);
	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

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

int	is_not_empty(t_lst *stack_a, t_arr arr, t_info info)
{
	while (stack_a)
	{
		if (stack_a->content >= arr.table[info.start]
			&& stack_a->content <= arr.table[info.end])
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	push_to_b(t_lst **stack_a, t_lst **stack_b, t_arr arr, t_info info)
{
	while (*stack_a)
	{
		while (is_not_empty(*stack_a, arr, info))
		{
			if ((*stack_a)->content >= arr.table[info.start]
				&& (*stack_a)->content <= arr.table[info.end])
			{
				pb(stack_a, stack_b);
				if ((*stack_b)->content < arr.table[info.mid])
					rb(stack_b);
			}
			else
				ra(stack_a);
		}
		info.start -= info.offset;
		info.end += info.offset;
		if (info.start < 0)
			info.start = 0;
		if (info.end >= arr.size)
			info.end = arr.size - 1;
	}
}

t_info	informations(t_arr *arr)
{
	t_info	inf;

	inf.mid = arr->size / 2 - 1;
	if (arr->size <= 100)
		inf.div = 8;
	else
		inf.div = 11;
	inf.offset = arr->size / inf.div;
	inf.start = inf.mid - inf.offset;
	inf.end = inf.mid + inf.offset;
	return (inf);
}
int	max_stack_b(t_lst *stack_b)
{
	int	max;

	max = stack_b->content;
	while (stack_b)
	{
		if (stack_b->content > max)
			max = stack_b->content;
		stack_b = stack_b->next;
	}
	return (max);
}
int	get_pos(t_lst *stack_a, int content)
{
	int	position;

	position = 0;
	while (stack_a)
	{
		if (stack_a->content == content)
			return (position);
		position++;
		stack_a = stack_a->next;
	}
	return (position);
}
int	get_index(t_arr arr, int content)
{
	int	index;

	index = 0;
	while (index < arr.size)
	{
		if (arr.table[index] == content)
			return (index);
		index++;
	}
	return (index);
}

void	stack_index(t_lst **stack, t_arr arr)
{
	t_lst	*head;

	head = *stack;
	while ((*stack) != NULL)
	{
		(*stack)->index = get_index(arr, (*stack)->content);
		(*stack) = (*stack)->next;
	}
	*stack = head;
}

int	look_for_next(t_lst *stack, int index)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == index)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}
int	search_next(t_lst *stack, int index)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == index)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}
int	is_sorted(t_lst *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}
void	back_to_a(t_lst **stack_a, t_lst **stack_b, int size)
{
	while (*stack_b || !is_sorted(*stack_a))
	{
		if (*stack_b && (*stack_b)->index == (*stack_a)->index - 1)
		{
			pa(stack_a, stack_b);
		}
		else if (ft_lstlast(*stack_a)->index == (*stack_a)->index - 1)
			rra(stack_a);
		else if (*stack_b && (ft_lstlast(*stack_a)->index == size - 1
					|| (*stack_b)->index > ft_lstlast(*stack_a)->index))
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else if (ft_lstsize(*stack_b) > 1)
		{
			if (search_next(*stack_b, (*stack_a)->index
					- 1) < ft_lstsize(*stack_b) / 2)
				rb(stack_b);
			else
			{
				rrb(stack_b);
			}
		}
	}
}

void	large_sort(t_lst **stack_a, t_lst **stack_b)
{
	t_info	info;
	t_arr	table;
	int		max;

	table = fill_sort_array(*stack_a);
	stack_index(stack_a, table);
	info = informations(&table);
	push_to_b(stack_a, stack_b, table, info);
	max = max_stack_b(*stack_b);
	info.position = get_pos(*stack_b, max);
	while (info.position-- > 0)
		rb(stack_b);
	pa(stack_a, stack_b);
	back_to_a(stack_a, stack_b, table.size);
	// printf("stack_a\n");
	// affiche_stack(*stack_a);
	// printf("stack_b\n");
	// affiche_stack(*stack_b);
	// printf("-----------\n");
}
