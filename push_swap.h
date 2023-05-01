/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:48:22 by ahaidour          #+#    #+#             */
/*   Updated: 2023/04/30 21:24:03 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_lst
{
	int				content;
	struct t_lst	*next;
	int				index;
}					t_lst;

typedef struct t_info
{
	int				div;
	int				mid;
	int				offset;
	int				start;
	int				end;
	int				position;
}					t_info;
typedef struct all
{
	char			*args;
	char			**arg_2d;
	int				size;
}					t_all;

typedef struct s_arr
{
	int		*table;
	int		size;
}			t_arr;

t_lst				*mylst_new(int content);
t_lst				*mylst_last(t_lst *lst);
void				mylstadd_back(t_lst **lst, t_lst *new);
void				mylstadd_front(t_lst **lst, t_lst *new);
int					mylst_size(t_lst *lst);
t_lst				*ft_lstlast(t_lst *lst);
int					issorted(t_lst *stack);

void				retour_erreur(void);
char				*arg_1d(char **av);
void				arg_check(int ac, char **av);
int					issorted(t_lst *stack);
int					min_index(t_lst *stack_a);
int					max_index(t_lst *stack_a);

void				sa(t_lst **stack);
void				sb(t_lst **stack);
void				ss(t_lst **stack_a, t_lst **stack_b);
void				pa(t_lst **stack_b, t_lst **stack_a);
void				pb(t_lst **stack_a, t_lst **stack_b);
void				ra(t_lst **stack);
void				rb(t_lst **stack);
void				rr(t_lst **stack_a, t_lst **stack_b);
void				rra(t_lst **stack);
void				rrb(t_lst **stack);
void				rrr(t_lst **stack_a, t_lst **stack_b);

void				sort_tree(t_lst **stack_a);
void				sort_five(t_lst **stack_a, t_lst **stack_b, int size);
void				large_sort(t_lst **stack_a, t_lst **stack_b);

void				affiche_stack(t_lst *stack_a);

#endif
