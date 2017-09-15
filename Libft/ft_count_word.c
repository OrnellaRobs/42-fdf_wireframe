/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:01:54 by orazafin          #+#    #+#             */
/*   Updated: 2016/12/13 16:31:08 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_word(char const *str, char c)
{
	int i;
	int flag;
	int word;

	i = 0;
	flag = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] == c)
			flag = 0;
		else if ((str[i] != c) && (flag == 0))
		{
			word++;
			flag = 1;
		}
		i++;
	}
	return (word);
}
