/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:48:18 by ahaidour          #+#    #+#             */
/*   Updated: 2023/04/28 18:41:50 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*load_data(t_all x)
{
	int		i;
	t_lst	*stack;
	t_lst	*new;
	int		tmp;

	stack = NULL;
	i = 0;
	while (x.arg_2d[i])
	{
		tmp = ft_atoi(x.arg_2d[i]);
		new = mylst_new(tmp);
		mylstadd_back(&stack, new);
		i++;
	}
	return (stack);
}

void	affiche_stack(t_lst *stack_a)
{
	while (stack_a != NULL)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
}

int	main(int ac, char **av)
{
	t_all	x;
	t_lst	*stack_a;
	t_lst	*stack_b;

	stack_b = NULL;
	if (ac > 1)
	{
		arg_check(ac, av);
		x.args = arg_1d(av);
		x.arg_2d = ft_split(x.args, ' ');
		stack_a = load_data(x);
		// stack_b = load_data(x);
		x.size = mylst_size(stack_a);
		if (!issorted(stack_a))
		{
			// printf("stack_a-------------------\n");
			// affiche_stack(stack_a);
			// printf("-------------------\n");
			if (x.size <= 3)
				sort_tree(&stack_a);
			if (x.size > 3 && x.size <= 5)
				sort_five(&stack_a, &stack_b, x.size);
			if (x.size > 5 && x.size <= 100)
			{
				large_sort(&stack_a, &stack_b, &x);
			}
			// printf("stack_a-------------------\n");
			// affiche_stack(stack_a);
			// printf("stack_b-------------------\n");
			// affiche_stack(stack_b);
		}
	}
	else
		retour_erreur();
	return (0);
}

// printf("stack_a\n");
// affiche_stack(stack_a);
// printf("stack_b\n");
// affiche_stack(stack_b);
// printf("-------------------\n");
// rra(&stack_a);
// ss(&stack_a, &stack_b);
// pa(&stack_a, &stack_b);
// pb(&stack_a, &stack_b);
// ra(&stack_a);
// rb(&stack_a);
// rrr(&stack_a, &stack_b);

// printf("stack_a\n");
// affiche_stack(stack_a);
// printf("stack_b\n");
// affiche_stack(stack_b);
