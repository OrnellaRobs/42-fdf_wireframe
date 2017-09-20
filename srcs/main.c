/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 18:24:20 by orazafin          #+#    #+#             */
/*   Updated: 2017/09/20 14:14:31 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdfhead.h"

void			create_new_image(t_set *setting)
{
	setting->img = mlx_new_image(setting->mlx, WIDTH, HEIGHT);
	setting->data = (int *)mlx_get_data_addr(setting->img, &(setting->bpp),
		&(setting->sl), &(setting->end));
}

void			draw(t_set *setting)
{
	draw_segment_horizontally(setting);
	draw_segment_vertically(setting);
	mlx_put_image_to_window(setting->mlx, setting->win, setting->img, 0, 0);
}

static void		initialize_setting(int fd, t_set *setting)
{
	if ((setting->map = get_map(fd, setting)) == NULL)
	{
		ft_putstr("Invalid map.\n");
		exit(EXIT_FAILURE);
	}
	setting->color_relief = ORANGE;
	setting->color_flat = ORANGE;
	setting->copy_color_relief = ORANGE;
	setting->copy_color_flat = ORANGE;
	setting->mlx = mlx_init();
	setting->depth = 1;
	setting->win = mlx_new_window(setting->mlx, WIDTH, HEIGHT, "FdF");
	create_new_image(setting);
}

int				main(int argc, char *argv[])
{
	int			fd;
	t_set		*setting;

	check_how_many_map(argc);
	if (!(setting = malloc(sizeof(t_set))))
		return (-1);
	if (!(fd = open_file(argv[1])))
		return (-1);
	ft_bzero(setting, sizeof(t_set));
	initialize_setting(fd, setting);
	draw(setting);
	write_welcome_message(setting);
	mlx_hook(setting->win, 2, (1L >> 0), my_key_funct, setting);
	mlx_hook(setting->win, 17, (1L << 17), proper_exit, setting);
	mlx_loop(setting->mlx);
	return (0);
}
