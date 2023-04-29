/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:30:53 by ahaidour          #+#    #+#             */
/*   Updated: 2023/04/29 16:18:37 by ahaidour         ###   ########.fr       */
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

int	is_not_empty(t_lst *stack_a, t_info info)
{
	while (stack_a)
	{
		if (stack_a->content >= info.arr[info.start] && stack_a->content <= info.arr[info.end])
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	push_to_b(t_lst **stack_a, t_lst **stack_b, t_info info)
{
	while (*stack_a)
	{
		while(is_not_empty(*stack_a, info))
		{
			if ((*stack_a)->content >= info.arr[info.start]
				&& (*stack_a)->content <= info.arr[info.end])
			{
				pb(stack_a, stack_b);
				if ((*stack_b)->content < info.arr[info.mid])
					rb(stack_b);
			}
			else
				ra(stack_a);
		}
		info.start -= info.offset;
		info.end += info.offset;
		if (info.start < 0)
			info.start = 0;
		if (info.end >= info.s)
			info.end = info.s - 1;
	}
}

t_info	informations(t_lst *stack_a, t_all *a)
{
	t_info	inf;

	inf.mid = a->size / 2 - 1;
	inf.arr = fill_sort_array(stack_a, a->size);
	inf.s = a->size;
	if (inf.s <= 100)
		inf.div = 5;
	else
		inf.div = 11;
	inf.offset = inf.s / inf.div;
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

int	get_index(t_info info, int content)
{
	int	index;

	index = 0;
	while (index < info.s)
	{
		if (info.arr[index] == content)
			return (index);
		index++;
	}
	return (index);
}

void	stack_index(t_lst **stack, t_info info)
{
	t_lst	*head;

	head = *stack;
	while ((*stack) != NULL)
	{
		(*stack)->index = get_index(info, (*stack)->content);
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
			pa(stack_a, stack_b);
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
			if (search_next(*stack_b, (*stack_a)->index - 1) <= ft_lstsize(*stack_b) / 2)
				rb(stack_b);

			else
			{
				rrb(stack_b);
				break;
			}

		}
	}
}


void	large_sort(t_lst **stack_a, t_lst **stack_b, t_all *a)
{
	t_info	info;
	int		max;

	info = informations(*stack_a, a);
	stack_index(stack_a, info);

	push_to_b(stack_a, stack_b, info);
	max = max_stack_b(*stack_b);
	info.position = get_pos(*stack_b, max);
	while (info.position-- > 0)
		rb(stack_b);
	pa(stack_a, stack_b);
	back_to_a(stack_a, stack_b, info.s);
	printf("stack_a\n");
	affiche_stack(*stack_a);
	printf("stack_b\n");
	affiche_stack(*stack_b);
	printf("-----------\n");
}
