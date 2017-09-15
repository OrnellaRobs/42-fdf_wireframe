/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:03:24 by orazafin          #+#    #+#             */
/*   Updated: 2016/12/13 13:23:56 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*dest_tmp;
	unsigned const char		*source_tmp;

	dest_tmp = (unsigned char *)dst;
	source_tmp = (unsigned const char *)src;
	if (source_tmp <= dest_tmp)
	{
		while (len--)
		{
			dest_tmp[len] = source_tmp[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
