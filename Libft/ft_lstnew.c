/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:50:28 by orazafin          #+#    #+#             */
/*   Updated: 2016/12/08 14:51:06 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new_list;

	if (!(new_list = malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new_list->content_size = 0;
		new_list->content = NULL;
	}
	else
	{
		new_list->content = malloc(content_size);
		if (new_list->content == NULL)
		{
			free(new_list);
			return (NULL);
		}
		ft_memcpy(new_list->content, content, content_size);
		new_list->content_size = content_size;
	}
	new_list->next = NULL;
	return (new_list);
}
