/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:19:41 by ahaidour          #+#    #+#             */
/*   Updated: 2023/03/27 17:00:33 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*arg_1d(char **av)
{
	int		i;
	char	*args;

	i = 1;
	args = av[i];
	i++;
	while (av[i])
	{
		args = ft_strjoin(args, ft_strjoin(" ", av[i]));
		i++;
	}
	i = 0;
	while (args[i])
	{
		if ((args[i] == '-' || args[i] == '+') && (args[i + 1] == '-' || args[i
				+ 1] == '+'))
			retour_erreur();
		i++;
	}
	return (args);
}

void	is_dup(char *a)
{
	char	**arg;
	int		i;
	int		j;

	arg = ft_split(a, ' ');
	i = 0;
	while (arg[i])
	{
		j = i + 1;
		while (arg[j])
		{
			if (ft_strcmp(arg[i], arg[j]) == 0)
				retour_erreur();
			j++;
		}
		i++;
	}
}

void	is_empty(int ac, char **av)
{
	int	i;
	int	exist;
	int	j;

	i = 0;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			retour_erreur();
		exist = 0;
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != 32 && av[i][j] != '\t')
			{
				exist = 1;
				break ;
			}
			j++;
		}
		if (exist == 0)
			retour_erreur();
		i++;
	}
}

// void	is_empty(int ac, char **av)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < ac)
// 	{
// 		if (ft_strlen(av[i]) == 0)
// 			retour_erreur();
// 		j = 0;
// 		while (av[i][j])
// 		{
// 			if (av[i][j] != 32 && av[i][j] != '\t')
// 				j = -2;
// 			j++;
// 		}
// 		if (j != -1)
// 			retour_erreur();
// 		i++;
// 	}
// }

void	arg_check(int ac, char **av)
{
	int		i;
	char	*args;

	i = 0;
	is_empty(ac, av);
	args = arg_1d(av);
	i = 0;
	while (args[i])
	{
		if (!(args[i] >= '0' && args[i] <= '9') && args[i] != 32
			&& args[i] != '-' && args[i] != '+' && args[i] != '\t')
			retour_erreur();
		i++;
	}
	is_dup(args);
}
