/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:31:41 by ahaidour          #+#    #+#             */
/*   Updated: 2023/05/06 15:29:26 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrr(t_lst **stack_a, t_lst **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

int	is_sorted(t_lst *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	test_if_same(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	choose_rule(t_lst **stack_a, t_lst **stack_b, char *rule)
{
	if (test_if_same(rule, "pa\n"))
		pa(stack_b, stack_a);
	else if (test_if_same(rule, "pb\n"))
		pb(stack_a, stack_b);
	else if (test_if_same(rule, "rr\n"))
		rr(stack_a, stack_b);
	else if (test_if_same(rule, "rra\n"))
		rra(stack_a);
	else if (test_if_same(rule, "rrb\n"))
		rrb(stack_b);
	else if (test_if_same(rule, "rrr\n"))
		rrr(stack_a, stack_b);
	else if (test_if_same(rule, "sa\n"))
		sa(*stack_a);
	else if (test_if_same(rule, "sb\n"))
		sb(*stack_b);
	else if (test_if_same(rule, "ss\n"))
		ss(*stack_a, *stack_b);
	else if (test_if_same(rule, "ra\n"))
		ra(stack_a);
	else if (test_if_same(rule, "rb\n"))
		rb(stack_b);
	else
		retour_err("Error !!");
}
