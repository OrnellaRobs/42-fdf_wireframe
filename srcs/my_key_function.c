/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_key_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 11:07:15 by orazafin          #+#    #+#             */
/*   Updated: 2017/09/21 13:29:42 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdfhead.h"

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

void		initialize_write_x_and_write_y(t_set *setting)
{
	setting->write_x = 15;
	setting->write_y = 15;
}

void		string_to_write_on_window(t_set *setting)
{
	write_option_to_change_color_relief(setting);
	write_on_window(setting, "\n", WHITE);
	write_option_to_change_color_flat(setting);
	setting->write_y += 400;
	write_other_options(setting);
	initialize_write_x_and_write_y(setting);
}

int			proper_exit(t_set *setting)
{
	ft_bzero(setting, sizeof(t_set));
	// free_int_tab(setting);
	exit(EXIT_SUCCESS);
	return (0);
}

int			my_key_funct(int keycode, t_set *setting)
{
	if (keycode == 53)
		proper_exit(setting);
	else
	{
		zoom(keycode, setting);
		increase_relief(keycode, setting);
		decrease_relief(keycode, setting);
		change_color_relief(keycode, setting);
		change_color_flat(keycode, setting);
		swap_color_between_relief_and_flat(keycode, setting);
		move_map(keycode, setting);
		reset(keycode, setting);
		mlx_destroy_image(setting->mlx, setting->img);
		create_new_image(setting);
		draw(setting);
		string_to_write_on_window(setting);
		setting->write_y = 15;
	}
	return (0);
}
