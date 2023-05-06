/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:20:42 by ahaidour          #+#    #+#             */
/*   Updated: 2023/05/06 15:26:33 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../ft_libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct all
{
	char	*args;
	char	**arg_2d;
	int		size;
}			t_all;

void		ft_free(char **str);
char		*arg_1d(char **av);
void		is_dup(char *stack_a);
void		is_empty(int ac, char **av);
void		arg_check(int ac, char **av);

void		retour_err(char *s);
void		retour_good(char *s);
char		*arg_1d(char **av);
void		is_dup(char *stack_a);
void		is_empty(int ac, char **av);
void		arg_check(int ac, char **av);
int			is_sorted(t_lst *stack_a);
int			test_if_same(char *s1, char *s2);
void		choose_rule(t_lst **stack_a, t_lst **stack_b, char *rule);

void		pa(t_lst **stack_b, t_lst **stack_a);
void		pb(t_lst **stack_a, t_lst **stack_b);
void		ra(t_lst **stack_a);
void		rb(t_lst **stack_b);
void		rr(t_lst **stack_a, t_lst **stack_b);
void		rra(t_lst **stack_a);
void		rrb(t_lst **stack_b);
void		rrr(t_lst **stack_a, t_lst **stack_b);
void		sa(t_lst *stack_a);
void		sb(t_lst *stack_b);
void		ss(t_lst *stack_a, t_lst *stack_b);

#endif
