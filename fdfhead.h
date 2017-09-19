/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfhead.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 13:20:36 by orazafin          #+#    #+#             */
/*   Updated: 2017/09/19 19:15:03 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDFHEAD_H
# define FDFHEAD_H

# include "./Libft/libft.h"
# include <stdio.h> //A ENLEVER POUR LE RENDU!!!!!!!!!!!
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "minilibx_macos/mlx.h"

# define SIZE_MAXI 1000
# define WIDTH 1200
# define HEIGHT 990
# define INTERVAL 30
# define WHITE 0XFFFFFF
# define RED 0XFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define ORANGE 0xFF8000
# define YELLOW 0xFFFF00
# define PINK 0xFE2E64
# define X0 2
# define Y0 2

typedef struct		s_set
{
	int				**map;
	int				color;
	int				color_relief;
	int				color_flat;
	int				copy_color_relief;
	int				copy_color_flat;
	int				column;
	int				column_max;
	int				line;
	void			*mlx;
	void			*win;
	void			*img;
	int				*data;

	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
	int				move_h;
	int				move_v;
	int				zoom;
	int				write_x;
	int				write_y;
	int				interval;
	int				flag;
	int				h;
	int				w;
	int				depth;

	int				bpp;
	int				sl;
	int				end;
}					t_set;

int					main(int argc, char *argv[]);
int			 		**get_map(int fd, t_set *setting);
int					check_valid_map(char **tab);
void				free_first_tab(char **tab);
void				draw_segment_horizontally(t_set *setting);
void				draw_segment_vertically(t_set *setting);
int					my_key_funct(int keycode, t_set *setting);
void				create_new_image(t_set *setting);
void				free_int_tab(t_set *setting);
void				write_on_window(t_set *setting, char *str, int color);
void				draw(t_set *setting);
void				initialize_bresenham(t_set *setting, int i, int j,
	int sens);
void				bresenham_algorithm(t_set *setting, int line, int column,
	int sens);
void				initialize_write_x_and_write_y(t_set *setting);
# endif
