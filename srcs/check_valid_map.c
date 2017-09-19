/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 19:08:51 by orazafin          #+#    #+#             */
/*   Updated: 2017/09/19 19:10:23 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdfhead.h"

int				check_valid_map(char **tab)
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
				if (tab[i][j] < '0' || tab[i][j] > '9' )
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
