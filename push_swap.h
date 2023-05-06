/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:48:22 by ahaidour          #+#    #+#             */
/*   Updated: 2023/05/06 15:26:56 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_info
{
	int		div;
	int		mid;
	int		offset;
	int		start;
	int		end;
	int		position;
}			t_info;

typedef struct all
{
	char	*args;
	char	**arg_2d;
	int		size;
}			t_all;

typedef struct s_arr
{
	int		*table;
	int		size;
}			t_arr;

void		ft_free(char **str);
t_lst		*load_content(t_all x);
void		retour_erreur(void);
char		*arg_1d(char **av);
void		arg_check(int ac, char **av);
int			is_sorted(t_lst *stack_a, t_lst *stack_b);
int			is_full(t_lst *a, t_arr array, t_info info);
int			min_index(t_lst *stack_a);
int			max_index(t_lst *stack_a);

void		sw(t_lst *h, char *s);
void		swap_both(t_lst *a, t_lst *b);
void		p(t_lst **from, t_lst **to, char *s);
void		r(t_lst **h, char *s);
void		rotate_both(t_lst **a, t_lst **b);
void		rr(t_lst **h, char *s);
void		rrr(t_lst **a, t_lst **b);

t_info		informations(t_arr *arr);
int			max_stack_b(t_lst *stack_b);
int			get_pos(t_lst *stack_a, int content);
int			get_index(t_arr arr, int content);
void		give_index(t_lst **stack, t_arr arr);
int			look_for_next(t_lst *stack, int index);

void		sort_tree(t_lst **stack_a);
void		sort_five(t_lst **stack_a, t_lst **stack_b, int size);
void		large_sort(t_lst **stack_a, t_lst **stack_b);

void		affiche_stack(t_lst *stack_a);

#endif
