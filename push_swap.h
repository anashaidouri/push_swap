/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:48:22 by ahaidour          #+#    #+#             */
/*   Updated: 2023/04/07 17:49:26 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_node
{
	int				content;
	struct t_node	*next;
}					t_node;

typedef struct all
{
	char			*args;
	char			**arg_2d;
	int				size;
}					t_all;

t_node				*mylst_new(int content);
t_node				*mylst_last(t_node *lst);
void				mylstadd_back(t_node **lst, t_node *new);
void				mylstadd_front(t_node **lst, t_node *new);
int					mylst_size(t_node *lst);
int					issorted(t_node *stack);

void				retour_erreur(void);
char				*arg_1d(char **av);
void				arg_check(int ac, char **av);
int					issorted(t_node *stack);
int					min_index(t_node *stack_a);

void				sa(t_node **stack);
void				sb(t_node **stack);
void				ss(t_node **stack_a, t_node **stack_b);
void				pa(t_node **stack_b, t_node **stack_a);
void				pb(t_node **stack_a, t_node **stack_b);
void				ra(t_node **stack);
void				rb(t_node **stack);
void				rr(t_node **stack_a, t_node **stack_b);
void				rra(t_node **stack);
void				rrb(t_node **stack);
void				rrr(t_node **stack_a, t_node **stack_b);

void				sort_tree(t_node **stack_a);
void				sort_five(t_node **stack_a, t_node **stack_b, int size);

void				affiche_stack(t_node *stack_a);

#endif
