/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:59:41 by ahaidour          #+#    #+#             */
/*   Updated: 2023/05/06 17:34:33 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	min_index(t_lst *stack_a)
{
	int	index;
	int	min;
	int	i;

	index = 0;
	i = 0;
	min = stack_a->content;
	while (stack_a != NULL)
	{
		if (min > stack_a->content)
		{
			min = stack_a->content;
			i = index;
		}
		stack_a = stack_a->next;
		index++;
	}
	return (i);
}

int	max_index(t_lst *stack_a)
{
	int	index;
	int	max;
	int	i;

	index = 0;
	i = 0;
	max = stack_a->content;
	while (stack_a != NULL)
	{
		if (max < stack_a->content)
		{
			max = stack_a->content;
			i = index;
		}
		stack_a = stack_a->next;
		index++;
	}
	return (i);
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

t_lst	*load_content(t_all x)
{
	int			i;
	t_lst		*stack;
	t_lst		*new;
	long int	tmp;

	stack = NULL;
	i = 0;
	while (x.arg_2d[i])
	{
		tmp = ft_atoi(x.arg_2d[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			retour_erreur();
		new = ft_lstnew(tmp);
		ft_lstadd_back(&stack, new);
		i++;
	}
	return (stack);
}

