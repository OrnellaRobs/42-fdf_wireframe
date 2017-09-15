/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:53:01 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/02 17:55:34 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_int(int n)
{
	int result;

	result = 0;
	if (n < 0)
	{
		result += ft_putchar_int('-');
		if ((n / 10) != 0)
			ft_putnbr_int((n / 10) * (-1));
		ft_putnbr_int((n % 10) * (-1));
	}
	else if (n > 9)
	{
		ft_putnbr_int(n / 10);
		ft_putnbr_int(n % 10);
	}
	else if (n >= 0 && n <= 9)
		result += ft_putchar_int(n + '0');
	return (result);
}
