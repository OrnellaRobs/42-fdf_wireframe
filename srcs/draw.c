/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 15:43:45 by orazafin          #+#    #+#             */
/*   Updated: 2017/09/15 23:17:23 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdfhead.h"

void		initialize_bresenham(t_set *setting, int i, int j, int sens)
{
	setting->x0 = setting->w - setting->h;
	setting->y0 = (setting->w + setting->h - setting->map[i][j] * setting->depth) / 2;
	if (sens == 1)
	{
		setting->x1 = setting->w + setting->interval - setting->h;
		setting->y1 = (setting->w + setting->interval + setting->h -
		setting->map[i][j + 1] * setting->depth) / 2;
	}
	else
	{
		setting->x1 = setting->w - setting->interval - setting->h;
		setting->y1 = (setting->w + setting->interval + setting->h -
			setting->map[i + 1][j] * setting->depth) / 2;
	}
	setting->dx = abs(setting->x1 - setting->x0);
	setting->dy = abs(setting->y1 - setting->y0);
	setting->sx = setting->x0 < setting->x1 ? 1 : -1;
	setting->sy = setting->y0 < setting->y1 ? 1 : -1;
	setting->err = (setting->dx > setting->dy ? setting->dx : -setting->dy) / 2;
}

void 		check_color(t_set *setting, int i, int j, int sens)
{
	if (sens > 0 && setting->map[i][j] != 0 && j + 1 < setting->column &&
		setting->map[i][j + 1] != 0 && setting->flag == 1)
			setting->color = setting->color_relief;
	else if (sens > 0 && setting->map[i][j] != 0 && j - 1 >= 0 &&
		setting->map[i][j - 1] != 0 && setting->flag == -1)
		setting->color = setting->color_relief;
	else if (sens < 0 && setting->map[i][j] != 0 && i + 1 < setting->line &&
		setting->map[i + 1][j] != 0 && setting->flag == 1)
			setting->color = setting->color_relief;
	else if (sens < 0 && setting->map[i][j] != 0 && i - 1 >= 0 &&
		setting->map[i - 1][j] != 0 && setting->flag == -1)
		setting->color = setting->color_relief;
	else
		setting->color = setting->color_flat;
}

void		draw_setting(t_set *setting, int line, int column, int sens)
{
	while(1)
	{
		if (setting->x0 > 0 && setting->x0 < WIDTH && setting->y0 > 0 &&
		setting->y0 < HEIGHT)
		{
			check_color(setting, line, column, sens);
			setting->data[setting->x0 + setting->y0 * WIDTH] = setting->color;
		}
		if (setting->x0 == setting->x1 && setting->y0 == setting->y1)
			break;
		setting->e2 = setting->err;
		if (setting->e2 > -(setting->dx))
		{
			setting->err -= setting->dy;
			setting->x0 += setting->sx;
		}
		if (setting->e2 < setting->dy)
		{
			setting->err += setting->dx;
			setting->y0 += setting->sy;
		}
	}
}

void 		draw_segment_horizontally(t_set *setting)
{
	int i;
	int j;
	int sens;

	sens = 1;
	i = 0;
	setting->interval = INTERVAL + setting->zoom;
	setting->h = -setting->interval + setting->move_v;
	while (i < setting->line)
	{
		j = 0;
		setting->x0 = 0;
		setting->w = (WIDTH / 2) + setting->move_h;
		while (j < setting->column - 1)
		{
			initialize_bresenham(setting, i ,j, sens);
			if (setting->map[i][j] >= setting->map[i][j + 1])
			{
				setting->flag = 1;
				draw_setting(setting, i, j, sens);
			}
			else
			{
				setting->flag = -1;
				draw_setting(setting, i, j + 1, sens);
			}
			setting->w += setting->interval;
			j++;
		}
		i++;
		setting->h += setting->interval;
	}
}

void 		draw_segment_vertically(t_set *setting)
{
	int i;
	int j;
	int sens;

	sens = -1;
	j = 0;
	setting->interval = INTERVAL + setting->zoom;
	setting->w = (WIDTH / 2) + setting->move_h;
	while (j < setting->column)
	{
		i = 0;
		setting->y0 = 0;
		setting->h = -setting->interval + setting->move_v;
		while (i < setting->line - 1)
		{
			initialize_bresenham(setting, i ,j, sens);
			if (setting->map[i][j] >= setting->map[i + 1][j])
			{
				setting->flag = 1;
				draw_setting(setting, i, j, sens);
			}
			else
			{
				setting->flag = -1;
				draw_setting(setting, i + 1, j, sens);
			}
			setting->h += setting->interval;
			i++;
		}
		j++;
		setting->w += setting->interval;
	}
}
