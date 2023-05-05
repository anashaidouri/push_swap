/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:20:12 by ahaidour          #+#    #+#             */
/*   Updated: 2023/05/04 19:26:15 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		stack_a = load_content(x);
		x.size = ft_lstsize(stack_a);
		if (!issorted(stack_a))
		{
		}

	}
	else
		retour_erreur();
	return (0);
}
