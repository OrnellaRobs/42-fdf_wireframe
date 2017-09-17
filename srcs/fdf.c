/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 18:24:20 by orazafin          #+#    #+#             */
/*   Updated: 2017/09/17 23:56:44 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdfhead.h"

void		create_new_image(t_set *setting)
{
	setting->img = mlx_new_image(setting->mlx, WIDTH, HEIGHT);
	setting->data = (int *)mlx_get_data_addr(setting->img, &(setting->bpp),
		&(setting->sl), &(setting->end));
}

void 		initialize_setting(int fd, t_set *setting)
{
	setting->map = get_map(fd, setting);
	setting->color_relief = ORANGE;
	setting->color_flat = ORANGE;
	setting->copy_color_relief = ORANGE;
	setting->copy_color_flat = ORANGE;
	setting->mlx = mlx_init();
	// setting->relief = 0;
	// setting->move_h = 0;
	// setting->move_v = 0;
	// setting->zoom = 0;
	setting->depth = 1;
	setting->win = mlx_new_window(setting->mlx, WIDTH, HEIGHT, "FdF");
	create_new_image(setting);
}

void		free_map(t_set *setting)
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

void 		draw(t_set *setting)
{
	draw_segment_horizontally(setting);
	draw_segment_vertically(setting);
	mlx_put_image_to_window(setting->mlx, setting->win, setting->img, 0, 0);
}

int			main(int argc, char *argv[])
{
	int			fd;
	t_set		*setting;

	if (!(setting = malloc(sizeof(t_set))))
		return (-1);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	ft_bzero(setting, sizeof(t_set));
	initialize_setting(fd, setting);
	draw(setting);
	setting->write_x = 500;
	setting->write_y = 50;
	write_on_window(setting, "WELCOME ON FDF - WIREFRAME", ORANGE);
	setting->write_x = 480;
	setting->write_y += 15;
	write_on_window(setting, "- Press the spacebar to BEGIN -", PINK);
	setting->write_x = 15;
	setting->write_y = 15;
	mlx_hook(setting->win, 2, (1L >> 0), my_key_funct, setting);
	mlx_loop(setting->mlx);
	free_map(setting);
	return (0);
}
