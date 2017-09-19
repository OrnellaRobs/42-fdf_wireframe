/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment_vertically.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 00:11:09 by orazafin          #+#    #+#             */
/*   Updated: 2017/09/20 00:15:16 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdfhead.h"

static void		apply_bresenham_for_each_line(t_set *setting, int i, int j,
	int sens)
{
	while (i < setting->line - 1)
	{
		initialize_bresenham(setting, i ,j, sens);
		if (setting->map[i][j] >= setting->map[i + 1][j])
		{
			setting->flag = 1;
			bresenham_algorithm(setting, i, j, sens);
		}
		else
		{
			setting->flag = -1;
			bresenham_algorithm(setting, i + 1, j, sens);
		}
		setting->h += setting->interval;
		i++;
	}
}

void			draw_segment_vertically(t_set *setting)
{
	int	i;
	int	j;
	int	sens;

	sens = -1;
	j = 0;
	setting->interval = INTERVAL + setting->zoom;
	setting->w = (WIDTH / 2) + setting->move_h;
	while (j < setting->column)
	{
		i = 0;
		setting->y0 = 0;
		setting->h = -setting->interval + setting->move_v;
		apply_bresenham_for_each_line(setting, i, j, sens);
		j++;
		setting->w += setting->interval;
	}
}
