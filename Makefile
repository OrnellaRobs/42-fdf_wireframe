# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/13 15:07:06 by orazafin          #+#    #+#              #
#    Updated: 2017/09/13 15:17:24 by orazafin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = 	fdf.c\
		ft_parsing.c\
		my_key_function.c\

SRCDIR = ./srcs/

OBJ = $(SRC:.c=.o)

LIBSRC =	get_next_line.c\
			ft_strsplit.c\

LIBOBJ = $(LIBSRC:.c=.o)

CFLAGS = -g -Wall -Werror -Wextra

LIBDIR = ./Libft/
OBJDIR = ./objs/
SRCDIRC = ./srcs/

SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(OBJ))

LIBS = Libft/libft.a

all : $(NAME)

BLUE = \x1b[34m
GREEN = \x1b[32m
RED = \x1b[31m
YELLOW = \x1b[33m
CYAN = \x1b[36m
B = \x1b[1m
EOC = \x1b[0m

$(NAME) :
	@ echo "$(B)$(CYAN)Compiling library libft...$(EOC)"
	@ make -C Libft/ re
	@ gcc -o $(NAME) -I fdfhead.h $(SRCS)
	@ mkdir -p $(OBJDIR)
	@ mv $(OBJ) $(OBJDIR)
	@ echo "$(B)$(BLUE)Library libft compilation completed $(B)$(GREEN)✔$(EOC)"

clean :
	@ echo "$(B)$(YELLOW)Deleting objects...$(EOC)"
	@ rm -rf objs
	@ echo "$(B)$(GREEN)Deleting done$(EOC)"
	@ make -C Libft/ clean

fclean : clean
	@ rm -rf $(NAME)
	@ echo "$(B)$(RED)Deleting library...$(EOC)"
	@ make -C Libft/ fclean
	@ echo "$(B)$(GREEN)Deleting library done$(EOC)"

re : fclean all
