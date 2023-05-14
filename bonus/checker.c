/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:20:12 by ahaidour          #+#    #+#             */
/*   Updated: 2023/05/14 16:54:56 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_all	init(int ac, char **av)
{
	t_all	x;

	arg_check(ac, av);
	x.args = arg_1d(av);
	x.arg_2d = ft_split(x.args, ' ');
	return (x);
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
			retour_err("Error !!");
		new = ft_lstnew(tmp);
		ft_lstadd_back(&stack, new);
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
	char	*rule;
	t_lst	*stack_a;
	t_lst	*stack_b;

	if (ac > 1)
	{
		stack_b = NULL;
		x = init(ac, av);
		stack_a = load_content(x);
		x.size = ft_lstsize(stack_a);
		while (1)
		{
			rule = get_next_line(0);
			if (!rule)
				break ;
			choose_rule(&stack_a, &stack_b, rule);
			free(rule);
		}
		affiche_stack(stack_a);
		if (is_sorted(stack_a))
			retour_good("OK");
		else
			retour_err("KO");
	}
	return (0);
}
