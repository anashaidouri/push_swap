/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:13:27 by ahaidour          #+#    #+#             */
/*   Updated: 2023/05/06 17:37:11 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	retour_err(char *s)
{
	ft_printf("%s\n", s);
	exit(EXIT_FAILURE);
}

void	retour_good(char *s)
{
	ft_printf("%s\n", s);
	exit(EXIT_SUCCESS);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
