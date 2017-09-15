/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:04:25 by orazafin          #+#    #+#             */
/*   Updated: 2016/12/13 14:24:20 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t len_dest;
	size_t len_src;

	i = 0;
	len_dest = ft_strlen((const char *)dest);
	len_src = ft_strlen(src);
	if (n < len_dest)
		return (n + len_src);
	if (!n)
		return (len_src);
	while (src[i] != '\0' && (len_dest + 1 + i) < n)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
