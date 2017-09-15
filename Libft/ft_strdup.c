/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:42:12 by orazafin          #+#    #+#             */
/*   Updated: 2016/12/13 14:18:18 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		nb;

	nb = ft_strlen(src);
	if (!(dest = (char *)malloc(sizeof(char) * (nb + 1))))
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}
