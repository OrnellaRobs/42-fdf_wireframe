/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:46:32 by orazafin          #+#    #+#             */
/*   Updated: 2017/09/19 22:47:15 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdfhead.h"

void		free_int_tab(t_set *setting)
{
	int i;

	i = 0;
	while (i < setting->line)
	{
		free(setting->map[i]);
		i++;
	}
	free(setting->map);
}
