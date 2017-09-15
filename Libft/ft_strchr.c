/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 09:00:15 by orazafin          #+#    #+#             */
/*   Updated: 2016/12/14 16:56:01 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	int		end;

	i = 0;
	str = (char *)s;
	end = ft_strlen(s);
	if (c == '\0')
		return (&str[end]);
	while ((char)str[i] != '\0')
	{
		if ((char)str[i] == c)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
