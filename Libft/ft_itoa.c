/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 23:38:48 by orazafin          #+#    #+#             */
/*   Updated: 2017/06/06 19:42:02 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_last_number(int number)
{
	if (number < 0)
		return (0 - number);
	return (number);
}

char			*ft_itoa(int n)
{
	char	*tab;
	int		total_number;
	int		negatif;

	negatif = 0;
	total_number = 0;
	if (n < 0)
	{
		negatif = 1;
		total_number = 1;
	}
	total_number += ft_intlen(n);
	if (!(tab = (char*)malloc(sizeof(char) * (total_number + 1))))
		return (NULL);
	tab[total_number] = '\0';
	total_number--;
	while (total_number >= negatif)
	{
		tab[total_number] = (char)(get_last_number(n % 10) + '0');
		n = n / 10;
		total_number--;
	}
	if (negatif == 1)
		tab[total_number] = '-';
	return (tab);
}
