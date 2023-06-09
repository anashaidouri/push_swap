/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:48:18 by ahaidour          #+#    #+#             */
/*   Updated: 2023/05/14 16:38:06 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all	first(int ac, char **av)
{
	t_all	x;

	arg_check(ac, av);
	x.args = arg_1d(av);
	x.arg_2d = ft_split(x.args, ' ');
	return (x);
}

int	main(int ac, char **av)
{
	t_all	x;
	t_lst	*stack_a;
	t_lst	*stack_b;

	stack_b = NULL;
	if (ac > 1)
	{
		x = first(ac, av);
		stack_a = load_content(x);
		x.size = ft_lstsize(stack_a);
		if (!is_sorted(stack_a, stack_b))
		{
			if (x.size <= 3)
				sort_tree(&stack_a);
			else if (x.size > 3 && x.size <= 5)
				sort_five(&stack_a, &stack_b, x.size);
			else
				large_sort(&stack_a, &stack_b);
		}
		ft_free(x.arg_2d);
	}
	return (0);
}
