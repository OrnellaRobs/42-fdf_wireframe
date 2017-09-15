/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:18:56 by orazafin          #+#    #+#             */
/*   Updated: 2016/12/11 19:42:39 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (((i < n) && (s1[i] || s2[i])))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - s2[i]);
		else if (s1[i] == s2[i])
			i++;
	}
	return (0);
}
