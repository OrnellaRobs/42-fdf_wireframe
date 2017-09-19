/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map_and_zoom.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 00:09:26 by orazafin          #+#    #+#             */
/*   Updated: 2017/09/20 00:09:48 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdfhead.h"

void		move_map(int keycode, t_set *setting)
{
	if (keycode == 124)
		setting->move_h += 5;
	else if (keycode == 123)
		setting->move_h -= 5;
	else if (keycode == 125)
		setting->move_v += 5;
	else if (keycode == 126)
		setting->move_v -= 5;
}

void		zoom(int keycode, t_set *setting)
{
	if (keycode == 24)
		setting->zoom += 5;
	else if (keycode == 27)
		setting->zoom -= 5;
}
