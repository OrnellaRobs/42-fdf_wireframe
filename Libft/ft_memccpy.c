/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:46:30 by orazafin          #+#    #+#             */
/*   Updated: 2016/12/13 13:23:43 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t					i;
	unsigned char			*dest_tmp;
	unsigned const char		*source_tmp;

	i = 0;
	dest_tmp = (unsigned char *)dest;
	source_tmp = (unsigned const char *)src;
	while (i < n)
	{
		dest_tmp[i] = source_tmp[i];
		if ((char)source_tmp[i] == c)
			return (dest_tmp + (i + 1));
		i++;
	}
	return (NULL);
}
