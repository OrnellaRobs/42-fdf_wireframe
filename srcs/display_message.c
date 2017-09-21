/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:59:01 by orazafin          #+#    #+#             */
/*   Updated: 2017/09/21 13:14:41 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdfhead.h"

void		write_on_window(t_set *setting, char *str, int color)
{
	mlx_string_put(setting->mlx, setting->win,
		setting->write_x, setting->write_y, color, str);
	setting->write_y += 20;
}

void		write_welcome_message(t_set *setting)
{
	setting->write_x = 500;
	setting->write_y = 50;
	write_on_window(setting, "WELCOME ON FDF - WIREFRAME", ORANGE);
	setting->write_x = 500;
	setting->write_y += 15;
	write_on_window(setting, "- Press any key to BEGIN -", PINK);
	initialize_write_x_and_write_y(setting);
}

void		write_option_to_change_color_flat(t_set *setting)
{
	write_on_window(setting, "COLOR FLAT:", WHITE);
	write_on_window(setting, "1 -> RED", RED);
	write_on_window(setting, "2 -> GREEN", GREEN);
	write_on_window(setting, "3 -> BLUE", BLUE);
	write_on_window(setting, "4 -> WHITE", WHITE);
	write_on_window(setting, "5 -> ORANGE", ORANGE);
	write_on_window(setting, "6 -> YELLOW", YELLOW);
	write_on_window(setting, "7 -> PINK", PINK);
}

void		write_option_to_change_color_relief(t_set *setting)
{
	write_on_window(setting, "COLOR RELIEF:", WHITE);
	write_on_window(setting, "R -> RED", RED);
	write_on_window(setting, "G -> GREEN", GREEN);
	write_on_window(setting, "B -> BLUE", BLUE);
	write_on_window(setting, "W -> WHITE", WHITE);
	write_on_window(setting, "O -> ORANGE", ORANGE);
	write_on_window(setting, "Y -> YELLOW", YELLOW);
	write_on_window(setting, "P -> PINK", PINK);
}

void		write_other_options(t_set *setting)
{
	write_on_window(setting, "OTHERS OPTIONS:", PINK);
	write_on_window(setting, "Q -> INCREASE RELIEF", WHITE);
	write_on_window(setting, "Z -> DECREASE RELIEF", WHITE);
	write_on_window(setting, "shift -> SWAP COLOR", WHITE);
	write_on_window(setting, "+ and - -> ZOOM", WHITE);
	write_on_window(setting, "0 -> RESET", WHITE);
	write_on_window(setting, "enter -> INVERSE COLOR", WHITE);
	write_on_window(setting, "down arrow key -> MOVE DOWN", WHITE);
	write_on_window(setting, "up arrow key -> MOVE UP", WHITE);
	write_on_window(setting, "left arrow key -> MOVE LEFT", WHITE);
	write_on_window(setting, "right arrow key -> MOVE RIGHT", WHITE);
}
