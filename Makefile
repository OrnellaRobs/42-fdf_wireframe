# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/13 15:07:06 by orazafin          #+#    #+#              #
#    Updated: 2017/09/20 00:35:41 by orazafin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

NAME_LIB = Libft/libft.a

LIBX = minilibx_macos/libmlx.a

FR = -framework

OGL = OpenGl

AKT = AppKit

SRCS_FDF = srcs/change_color.c\
			srcs/change_relief.c\
			srcs/display_message.c\
			srcs/draw_bresenham_algorithm.c\
			srcs/draw_segment_horizontally.c\
			srcs/draw_segment_vertically.c\
			srcs/error_cases.c\
			srcs/fdf.c\
			srcs/free_int_tab.c\
			srcs/free_tab_parsing.c\
			srcs/move_map_and_zoom.c\
			srcs/my_key_function.c\
			srcs/open_file.c\
			srcs/parsing_get_map.c\

FLAGS += -Wall -Wextra -Werror

OBJS_FILLIT = (SRCS_FILLIT:.c=.o)

all : $(NAME)

$(NAME):
	@echo "compiling fdf..."
	@make -C Libft
	@gcc -g -o $(NAME) $(SRCS_FDF) $(NAME_LIB) $(LIBX) $(FR) $(OGL) $(FR) $(AKT)
	@echo "fdf done"

clean :
	@echo "deleting objects..."
	@make -C Libft clean
	@echo "deleting done"

fclean : clean
	@echo "deleting library and fdf..."
	@make -C Libft fclean
	@rm -f $(NAME)
	@echo "deleting done"

re : fclean all
