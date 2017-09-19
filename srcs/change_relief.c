/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_relief.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 00:05:58 by orazafin          #+#    #+#             */
/*   Updated: 2017/09/20 00:09:43 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdfhead.h"

void		increase_relief(int keycode, t_set *setting)
{
	if (keycode == 12)
		setting->depth += 2;
}

void		decrease_relief(int keycode, t_set *setting)
{
	if (keycode == 6)
		setting->depth -= 2;
}
