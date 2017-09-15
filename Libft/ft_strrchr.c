/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 09:08:20 by orazafin          #+#    #+#             */
/*   Updated: 2016/12/13 15:14:56 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		flag;
	size_t	end;

	end = ft_strlen(s);
	i = 0;
	flag = (-1);
	if (c == '\0')
		return ((char *)&s[end]);
	while (s[i])
	{
		if (s[i] == c)
			flag = i;
		i++;
	}
	if (flag > (-1))
		return ((char *)s + flag);
	return (0);
}
