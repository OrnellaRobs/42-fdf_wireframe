/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_key_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 11:07:15 by orazafin          #+#    #+#             */
/*   Updated: 2017/09/18 00:26:11 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//RAJOUTER LES KEYCODE POUR LES CHIFFRES DU CLAVIER NUMERIQUE
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

void		reset(int keycode, t_set *setting)
{
	if (keycode == 82 || keycode == 29)
	{
		setting->depth = 1;
		setting->move_h = 0;
		setting->move_v = 0;
		setting->color_relief = setting->copy_color_relief;
		setting->color_flat = setting->copy_color_flat;
		setting->zoom = 0;
	}
}

// void			change_relief_color_according_to_altitude(int keycode, t_set *setting)
// {
// 	if (setting->relief > 0)
// 		setting->color_relief = GREEN;
// 	else if (setting->relief < 0)
// 			setting->color_relief = BLUE;
// }

void 		move_right_left_top_bottom(int keycode, t_set *setting)
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
	printf("zoom");
	if (keycode == 24)
		setting->zoom += 5;
	else if (keycode == 27)
		setting->zoom -= 5;
}

void		write_on_window(t_set *setting, char *str, int color)
{
	mlx_string_put(setting->mlx, setting->win,
		setting->write_x, setting->write_y, color, str);
	setting->write_y += 20;
}

void 		write_option_to_change_color_flat(t_set *setting)
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
void 		write_option_to_change_color_relief(t_set *setting)
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

void 		write_other_options(t_set *setting)
{
	write_on_window(setting, "OTHERS OPTIONS:", PINK);
	write_on_window(setting, "Q -> INCREASE RELIEF", WHITE);
	write_on_window(setting, "Z -> DECREASE RELIEF", WHITE);
	write_on_window(setting, "0 -> RESET", WHITE);
	write_on_window(setting, "shift -> INVERSE COLOR", WHITE);
	write_on_window(setting, "down arrow key -> MOVE DOWN", WHITE);
	write_on_window(setting, "up arrow key -> MOVE UP", WHITE);
	write_on_window(setting, "left arrow key -> MOVE LEFT", WHITE);
	write_on_window(setting, "right arrow key -> MOVE RIGHT", WHITE);
	write_on_window(setting, "shift -> SWAP COLOR", WHITE);
}

void 		initialize_write_x_and_write_y(t_set *setting)
{
	setting->write_x = 15;
	setting->write_y = 15;
}
void		string_to_write_on_window(t_set *setting)
{
	write_option_to_change_color_relief(setting);
	write_on_window(setting, "\n", WHITE);
	write_option_to_change_color_flat(setting);
	setting->write_y += 450;
	write_other_options(setting);
	initialize_write_x_and_write_y(setting);
}
int			my_key_funct(int keycode, t_set *setting)
{
	printf("key event %d\n", keycode);
	if (keycode == 53)
	{
		free_map(setting);
		exit(EXIT_SUCCESS);
	}
	else
	{
		zoom(keycode, setting);
		increase_relief(keycode, setting);
		decrease_relief(keycode, setting);
		// change_relief_color_according_to_altitude(keycode, setting);
		change_color_relief(keycode, setting);
		change_color_flat(keycode, setting);
		swap_color_between_relief_and_flat(keycode, setting);
		move_right_left_top_bottom(keycode, setting);
		reset(keycode, setting);
		mlx_destroy_image(setting->mlx, setting->img);
		create_new_image(setting);
		draw(setting);
		string_to_write_on_window(setting);
		setting->write_y = 15;
	}
	return (0);
}
