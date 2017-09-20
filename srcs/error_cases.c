/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 19:08:51 by orazafin          #+#    #+#             */
/*   Updated: 2017/09/20 14:18:09 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdfhead.h"

void		check_how_many_map(int argc)
{
	if (argc == 1)
	{
		ft_putstr("usage: ./fdf map\n");
		exit(EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		ft_putstr("Too much map. Select only one.\n");
		exit(EXIT_FAILURE);
	}
}

int			check_valid_map(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] != '-')
			{
				if (tab[i][j] < '0' || tab[i][j] > '9')
					return (1);
			}
			else
			{
				if (tab[i][j + 1])
					if (tab[i][j + 1] < '0' || tab[i][j + 1] > '9')
						return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
