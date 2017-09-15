/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:45:42 by orazafin          #+#    #+#             */
/*   Updated: 2016/12/13 16:30:37 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**split(char const *s, char c, char **tab)
{
	unsigned int	i;
	unsigned int	taille;
	int				index;

	taille = 0;
	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] == c)
			taille = 0;
		else if (s[i] != c)
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				tab[index] = ft_strsub(s, (i - taille), taille + 1);
				index++;
			}
			taille++;
		}
		i++;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb;

	if (!s || !c)
		return (NULL);
	nb = ft_count_word(s, c);
	if (!(tab = (char **)malloc(sizeof(char*) * (nb + 1))))
		return (NULL);
	tab = split(s, c, tab);
	tab[nb] = NULL;
	return (tab);
}
