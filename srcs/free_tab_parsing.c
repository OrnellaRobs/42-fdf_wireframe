/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 19:09:59 by orazafin          #+#    #+#             */
/*   Updated: 2017/09/21 13:32:40 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdfhead.h"

void	free_first_tab(char **tab)
{
	int line;

	line = 0;
	while (tab[line])
	{
		free(tab[line]);
		line++;
	}
	free(tab);
}
