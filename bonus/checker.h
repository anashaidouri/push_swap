/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:20:42 by ahaidour          #+#    #+#             */
/*   Updated: 2023/05/04 19:24:22 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

void	retour_erreur(void);
char	*arg_1d(char **av);
void	is_dup(char *a);
void	is_empty(int ac, char **av);
void	arg_check(int ac, char **av);





#endif
