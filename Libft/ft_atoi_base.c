/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:11:41 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/26 18:53:51 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(const char *str, int base)
{
	int		i;
	int		negatif;
	long	res;

	i = 0;
	res = 0;
	while (ft_is_space(str) == 1)
		str++;
	negatif = (str[i] == '-') ? -1 : 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z')
	|| (str[i] >= 'A' && str[i] <= 'Z'))
	{
		if (str[i] > '9')
			res = res * base + ((str[i] <= 'z') ?
			str[i] - 'a' + 10 : str[i] - 'A' + 10);
		else
			res = res * base + str[i] - '0';
		i++;
	}
	return (res * negatif);
}
