/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment_horizontally.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 00:10:08 by orazafin          #+#    #+#             */
/*   Updated: 2017/09/20 14:19:28 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdfhead.h"

static void		apply_bresenham_for_each_column(t_set *setting, int i, int j,
	int sens)
{
	while (j < setting->column - 1)
	{
		initialize_bresenham(setting, i, j, sens);
		if (setting->map[i][j] >= setting->map[i][j + 1])
		{
			setting->flag = 1;
			bresenham_algorithm(setting, i, j, sens);
		}
		else
		{
			setting->flag = -1;
			bresenham_algorithm(setting, i, j + 1, sens);
		}
		setting->w += setting->interval;
		j++;
	}
}

void			draw_segment_horizontally(t_set *setting)
{
	int	i;
	int	j;
	int	sens;

	sens = 1;
	i = 0;
	setting->interval = INTERVAL + setting->zoom;
	setting->h = -setting->interval + setting->move_v;
	while (i < setting->line)
	{
		j = 0;
		setting->x0 = 0;
		setting->w = (WIDTH / 2) + setting->move_h;
		apply_bresenham_for_each_column(setting, i, j, sens);
		i++;
		setting->h += setting->interval;
	}
}
