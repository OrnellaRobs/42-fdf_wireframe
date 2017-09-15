/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 23:39:26 by orazafin          #+#    #+#             */
/*   Updated: 2016/12/13 11:03:11 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) == 0)
			flag = 0;
		else if (((ft_is_lower(str[i]) == 1) && (flag == 0)) || i == 0)
		{
			str[i] = ft_toupper(str[i]);
			flag = 1;
		}
		else if ((ft_is_lower(str[i]) == 0) && (flag == 0))
			flag = 1;
		else if ((ft_is_upper(str[i]) == 1) && (flag == 1))
			str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
