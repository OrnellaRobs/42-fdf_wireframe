/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:32:05 by orazafin          #+#    #+#             */
/*   Updated: 2016/12/13 13:23:34 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*dest_tmp;
	unsigned char const		*source_tmp;

	i = 0;
	dest_tmp = (unsigned char *)dest;
	source_tmp = (unsigned char const *)src;
	while (i < n)
	{
		dest_tmp[i] = source_tmp[i];
		i++;
	}
	return (dest_tmp);
}
