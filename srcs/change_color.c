/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 23:48:55 by orazafin          #+#    #+#             */
/*   Updated: 2017/09/20 00:43:13 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//AJOUTER POUR PINK LE CLAVIER NUMERIQUE
#include "../fdfhead.h"

void		swap_color(t_set *setting)
{
	int color;

	color = setting->color_relief;
	setting->color_relief = setting->color_flat;
	setting->color_flat = color;
}

void		change_color_relief(int keycode, t_set *setting)
{
	if (keycode == 15)
		setting->color_relief = RED;
	else if (keycode == 5)
		setting->color_relief = GREEN;
	else if (keycode == 11)
		setting->color_relief = BLUE;
	else if (keycode == 13)
		setting->color_relief = WHITE;
	else if (keycode == 31)
		setting->color_relief = ORANGE;
	else if (keycode == 16)
		setting->color_relief = YELLOW;
	else if (keycode == 35)
		setting->color_relief = PINK;
}

void		change_color_flat(int keycode, t_set *setting)
{
	if (keycode == 83 || keycode == 18)
		setting->color_flat = RED;
	else if (keycode == 84 || keycode == 19)
		setting->color_flat = GREEN;
	else if (keycode == 85 || keycode == 20)
		setting->color_flat = BLUE;
	else if (keycode == 21 || keycode == 86)
		setting->color_flat = WHITE;
	else if (keycode == 23 || keycode == 87)
		setting->color_flat = ORANGE;
	else if (keycode == 22 || keycode == 88)
		setting->color_flat = YELLOW;
	else if (keycode == 26)
		setting->color_flat = PINK;
}

void		swap_color_between_relief_and_flat(int keycode, t_set *setting)
{
	if (keycode == 258)
		swap_color(setting);
}
